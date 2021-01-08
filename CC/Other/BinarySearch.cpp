#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (auto &i: arr) {
        cin >> i;
    }

    int k;
    cin >> k;

    int l = 0, r = n-1;
    while (l <= r) {
        int m = l + (r-l)/2;
        if (arr[m] == k) {
            cout << "Present\n";
            break;
        }

        if (k < arr[m]) {
            r = m-1;
        } else {
            l = m+1;
        }
    }

    if (l > r) {
        cout << "Absent\n";
    }

    return 0;
}