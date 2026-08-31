// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 3;
    int rounds = 100;

    array<int, 3> cap;
    array<int, 3> milk;
    freopen("mixmilk.in", "r", stdin);
    for(int i = 0; i < n; n++) {
        cin >> cap[i];
        cin >> milk[i];
    }

    for(int j = 0; j < rounds; j++) {
        int cur = j % 3;
        int next = (j + 1) % 3;
        // Change is minimum between milk in current bucket and 
        // milk left to be added
        int change = min(milk[cur], cap[next] - milk[next]);
        milk[cur] -= change;
        milk[next] += change;
    }
    freopen("mixmilk.out", "w", stdout);
    for(int m: milk) {
        cout << m << "\n";
    }
    
}
