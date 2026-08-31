// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	/* 
        For each side, determine characters needed. Any overlap can
        disregard. like fox and box, you need f,b,o,x so simply can
        take max of num chars for each?..
    */ 
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    vector<int> res(26, 0);

    int N; cin >> N;
    for(int i=0; i<N; i++) {
        vector<int> a(26, 0); // a is chars the first word needs
        vector<int> b(26, 0); // b is chars 2nd word needs
        vector<int> c(26, 0);
        string front, back;
        cin >> front >> back;
        
        for(char c : front) {
            a[int(c) - int('a')] += 1;
        }

        for(char c : back) {
            b[int(c) - int('a')] += 1;
        }
        
        for(int j = 0; j < 26; j++) {
            c[j] = max(a[j], b[j]);
            res[j] += c[j];
        }
    }  

    for(int x : res) {
        cout << x << "\n";
    }

}
