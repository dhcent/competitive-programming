// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    // N, M is num sections for speed limits + betty's speed
    int N, M;
    cin >> N >> M;
    vector<vector<int>> limits;

    for(int i=0; i<N; i++) {
        int len, lim;
        cin >> len >> lim;
        limits.push_back({len, lim});
    }

    vector<vector<int>> betty;

    for(int i=0; i<M; i++) {
        int len, spd;
        cin >> len >> spd;
        betty.push_back({len, spd});
    }

    int rd_idx = 0, max_dif = 0;
    int rd_spd_lim;

    for(int i=0; i<M; i++) {
        int to_travel = betty[i][0];
        int spd = betty[i][1];
        while(to_travel > 0) {
            rd_spd_lim = limits[rd_idx][1];
            max_dif = max(max_dif, spd - rd_spd_lim);
            if(to_travel > limits[rd_idx][0]) {
                to_travel -= limits[rd_idx][0];
                rd_idx++;
            }
            else {
                limits[rd_idx][0] -= to_travel;
                to_travel = 0;
                if(limits[rd_idx][0] == 0) {
                    rd_idx++;
                }
            }
        }
    }

    cout << max_dif;
}
