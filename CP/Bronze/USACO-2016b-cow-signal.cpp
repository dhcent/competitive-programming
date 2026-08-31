// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

	int M, N, K;
    cin >> M >> N >> K;
    // Array's must know size at compile time. vectors support
    // dynamic sizing and thus can resize accordingly.
    vector<vector<char>> arr(M, vector<char>(N));

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < M; i++) {
        string line = "";
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < K; k++) {
                line += arr[i][j];
            }
        }
        
        for(int k = 0; k < K; k++) {
            cout << line << "\n";
        }

    }
}
