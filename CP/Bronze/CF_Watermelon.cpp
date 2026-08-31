// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {

    int a;
	cin >> a;
    if(a < 3) {
        cout << "NO" << "\n";
    }
    else if(a % 2 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}
