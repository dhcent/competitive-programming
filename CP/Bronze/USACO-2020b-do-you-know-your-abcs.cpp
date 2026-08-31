// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	/* 
        Sort the input array. The first two numbers must be A/B
        The last number must be A+B+C. Subtract last num from first 2
        to get C.
    */
    int arr[7] = {0};
    for(int i = 0; i < 7; i++) {
        cin >> arr[i]; 
    }

    int idx = 1;
    while(idx < 7) {
        int x = idx;
        while(x > 0 && arr[x - 1] > arr[x]) {
            int temp = arr[x - 1];
            arr[x - 1] = arr[x];
            arr[x] = temp;
            x--;
        }
        idx++;
    }
    int a = arr[0];
    int b = arr[1];
    int c = arr[6] - a - b;
    cout << a << " " << b << " " << c;
}
