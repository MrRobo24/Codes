#include <bits/stdc++.h>
#define LLI int
#define IN_ARR LLI n; cin >> n; LLI arr[n]; for (auto &i: arr) {cin >> i;}
#define OUT_ARR for (auto &i: arr) { cout << i << " ";} cout << "\n";
using namespace std;


int main() {
    IN_ARR
    for (int i=0;i<n-1;i++) {
        int minidx = i;
        for (int j=i+1;j<n;j++) {
            if (arr[j] < arr[minidx]) {
                minidx = j;
            }
        }
        swap(arr[minidx], arr[i]);
    }
    OUT_ARR
    return 0;
}