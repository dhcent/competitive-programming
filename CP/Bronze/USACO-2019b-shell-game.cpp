// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	/*  
        Create an unordered map with x,y,z as each shell. Have a 
        size 3 array of chars where we constantly swap the chars
        according to the swap. Then we perform the guess, adding one to 
        whichever shell it corresponds to on the unordered map
    */

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int swaps;
    cin >> swaps;
    array<char, 3> shells = {'x', 'y', 'z'};
    unordered_map<char, int> mp = {
        {'x', 0},
        {'y', 0},
        {'z', 0}
    };
    for(int i=0; i<swaps; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        a--; b--; g--;
        // swap
        char temp = shells[a];
        shells[a] = shells[b];
        shells[b] = temp;

        mp[shells[g]]++;
    }
    cout << max({mp['x'], mp['y'], mp['z']});
}
