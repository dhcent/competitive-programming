// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int problems;
    int counter = 0;
    cin >> problems;
    
    for(int i = 0; i < problems; i++) {
        int sum = 0;
        for(int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            sum += x;
        }
        if(sum > 1) {
            counter += 1;
        }
    }

    cout << counter;
}
