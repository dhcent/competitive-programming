// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
    vector<int> x_arr, y_arr;

    for(int i=0; i<N; i++) {
        int x; cin >> x;
        x_arr.push_back(x);
    }

    for(int i=0; i<N; i++) {
        int y; cin >> y;
        y_arr.push_back(y);
    }
    int max_sqr_d;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int dx = x_arr[i] - x_arr[j];
            int dy = y_arr[i] - y_arr[j];

            max_sqr_d = max(max_sqr_d, dx * dx + dy * dy);
        }
    }
    cout << max_sqr_d;
}
