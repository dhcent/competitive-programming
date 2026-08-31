// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

	int n, k;
    cin >> n >> k;

    int cur_char = 0, counter = 0;
    vector<string> res;
    string cur_to_add;
    string cur;
    while(counter < n) {
        cin >> cur;
        cur_char += (int)cur.size();
        if(cur_char > k) {
            cur_to_add.pop_back(); // remove the space at the end of the character
            res.push_back(cur_to_add);
            cur_to_add = "";
            cur_char = (int)cur.size();
        }
        cur_to_add += cur + " ";
        counter++;
    }
    if(cur_to_add != "") {
        cur_to_add.pop_back();
        res.push_back(cur_to_add);
    }

    for(int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << "\n";
    }
}
