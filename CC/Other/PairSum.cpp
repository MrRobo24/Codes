#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {
    LLI n, k;
    cin >> n >> k;
    LLI arr[n];

    for (LLI i=0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    LLI l = 0, r = n-1;
    LLI  sum = arr[l] + arr[r];
    while (l < r && sum != k) {
        if (sum < k) {
            l++;
        } else {
            r--;
        }
        sum = arr[l] + arr[r];
    }


    if (sum == k) {
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }

    return 0;

}