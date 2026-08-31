// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, n, w;

    cin >> k >> n >> w;
    int cost = k * (w * (w + 1)) / 2;
    if(n > cost) {
        cout << 0;
    }
    else {
        cout << cost - n;
    }
}
