// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Redirects stdin/stdout to not look at terminal but rather those files.
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

	int arr[4][2] = {0};
    int res[3] = {0};
    for(int i = 0; i < 4; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    /* Iterate backwards, find the difference. 
    like if 4 ppl plat and now 8, you can assume 4 ppl promoted
    from gold. Then look at difference of gold. if 5 ppl gold now 6,
    should be 1 ppl, but 5 ppl promoted from silver so 6, so we can 
    subtract the difference from plat, then put that onto gold. subtract
    the difference from new gold to final gold to find promoted from silver
    repeat until we hit bronze since we can't promote to bronze, so we assume
    thats the people that joined the countest after.
    3 - 8
    */
    int diff = 0;
    for(int j = 3; j >= 1; j--) {
        diff = arr[j][1] - arr[j][0];
        res[j - 1] += diff;
        arr[j - 1][0] -= diff;
    }

    cout << res[0] << "\n" << res[1] << "\n" << res[2] << "\n";
}   
