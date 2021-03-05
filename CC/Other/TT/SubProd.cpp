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

    LLI l = 0, r = k-1;
    if (k > n) {
        cout << "Out of bounds\n";
    } else {
        LLI p = 1, i = l;
        while (i<=r) {
            p *= arr[i];
            i++;
        }

        LLI minim = p, lm = l, rm = r;

        while (r <= n-1) {
            p = p/arr[l];
            l++;
            r++;
            p *= arr[r];
            cout << p << "PROD\n";

            if (minim > p) {
                minim = p;
                lm = l;
                rm = r;
            }
        }

        cout << lm << " " << rm << "\n";

    }

    return 0;

}