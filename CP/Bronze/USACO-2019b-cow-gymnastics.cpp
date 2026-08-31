// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    // used alot of ai to help ICL
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    // N cows, K sessions
    int N, K; cin >> K >> N;
    vector<int> ranks(N);

    for(int i = 0; i < N; i++) {
        cin >> ranks[i];
    }
    // consistent[a][b] implies ranks[a] < ranks[b]
    // aka a is better than b. 
    // note N+1 is for skipping 0 idx (so [1] is cow 1)
    vector<vector<bool>> consistent(N+1, vector<bool>(N+1, false));
    
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int betterCow = ranks[i];
            int worseCow = ranks[j];
            consistent[betterCow][worseCow] = true;
        }
    }

    for(int k = 1; k < K; k++) {
        // get all positions of cows in this curr session
        vector<int> pos(N+1);
        for(int i = 0; i < N; i++) {
            int cow; cin >> cow;
            pos[cow] = i;
        }
        // try all combinations of cows. If it was originally 
        // consistent, determine if it's no longer consistent
        for(int betterCow = 1; betterCow <= N; betterCow++) {
            for(int worseCow = 1; worseCow <= N; worseCow++) {
                if(consistent[betterCow][worseCow] &&
                    pos[betterCow] > pos[worseCow]) {
                        consistent[betterCow][worseCow] = false;
                    }
            }
        }
    }

    int res = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(consistent[i][j]) {
                res++;
            }
        }
    }

    cout << res;
}
