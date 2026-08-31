// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    unordered_map<char, int> mp = {
        {'.', -1},
        {'L', -1},
        {'B', 0},
        {'R', -2}
    };
    array<int,2> start;
    array<int,2> end;
    int dist_mp[10][10];
    char sqr;
    /* 
        populates map with -1 on empty spaces + lake, -2 on rock, and 0 at starting
    */
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> sqr;
            dist_mp[i][j] = mp.at(sqr);
            if(sqr == 'B') {
                start[0] = i;
                start[1] = j;
            }
            if(sqr == 'L') {
                end[0] = i;
                end[1] = j;
            }
        }
    }

    /* 
        Run a BFS process, starting from the search node and repeating until we reach lake.
        Begin by pushing start coordinate to queue. Then, add all the neighbors to queue along
        with a distance of 1. Then add 1 to distance for future entries. Repeat this for all first layer 
        neighbor nodes until we reach end, by which we can safely return distance stored to arrive
        at that node. since this is BFS, the distance we store is guaranteed to be shortest.
    */
    queue<array<int,2>> q;
    q.push(start);
    array<int,2> cur;
    while(q.size() != 0) {
        cur = q.front();
        if(cur == end) {
            cout << dist_mp[cur[0]][cur[1]] - 1; //lake itself does not count as a cow
            return 0;
        }
        q.pop();
        // add nx,ny. up, down, left, right. Only update if haven't seen yet.
        // This automatically skips rock since adding requires mp to have -1 and the squares
        // can only be added if it's empty space or "-1"
        int r = cur[0], c = cur[1], cur_d = dist_mp[r][c];

        if(r > 0 && dist_mp[r - 1][c] == -1) {
            q.push({r - 1, c});
            dist_mp[r - 1][c] = cur_d + 1;
        }
        if(r < 9 && dist_mp[r + 1][c] == -1) {
            q.push({r + 1, c});
            dist_mp[r + 1][c] = cur_d + 1;
        }
        if(c > 0 && dist_mp[r][c - 1] == -1) {
            q.push({r, c - 1});
            dist_mp[r][c - 1] = cur_d + 1;
        }
        if(cur[1] < 9 && dist_mp[r][c + 1] == -1) {
            q.push({r, c + 1});
            dist_mp[r][c + 1] = cur_d + 1;
        }
    }
    return 0;
}
