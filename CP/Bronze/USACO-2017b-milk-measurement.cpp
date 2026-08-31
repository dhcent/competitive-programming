// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    /* 
        Use an ordered set to organize the changes. Once we organize changes, 
        iterate through each change and if that changes the leader in any way 
        (if another cow catches up / replaces), add 1 to changes.
    */
    // Bessie, Elsie, Mildred

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    map<string, int> mp = {
        {"Bessie", 0},
        {"Elsie", 1},
        {"Mildred", 2}
    };
    vector<int> milk(3,7);
    vector<vector<int>> changes;
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int day, change;
        string cow, shift;
        cin >> day >> cow >> shift;
        change = stoi(shift);

        changes.push_back({day, mp[cow], change});
    }

    sort(changes.begin(), changes.end(), 
        [](vector<int> a, vector<int> b) { return a[0] < b[0]; });

    set<int> leaders;
    int res = 0;
    for(vector<int> event : changes) {
        milk[event[1]] += event[2];
        int max_milk = max(milk[0], max(milk[1], milk[2]));
        set<int> new_leader;
        for(int i = 0; i < 3; i++) {
            if(milk[i] == max_milk) {
                new_leader.insert(i);
            }
        }
        if(new_leader != leaders) {
            res += 1;
            leaders = new_leader;
        }
    }

    cout << res;

}
