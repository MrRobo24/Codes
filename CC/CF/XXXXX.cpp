//AC Later - TUT
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI t;
    cin >> t;
    while (t--) {
        LLI n, x;
        cin >> n >> x;
        LLI arr[n];
        LLI mlen = INT_MIN, sum = 0, curr = n, flag = 0;
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        LLI left = -1, right = -1;
        for (LLI i=0;i<n;i++) {
            if (arr[i] % x) {
                if (left == -1) {
                    left = i;
                }
                right = i;
            }
        }

        if (sum % x) {
            cout << n << "\n";
        } else if (left == -1) {
            cout << left << "\n";
        } else {
            cout << max(n-left-1, right) << "\n";
        }

    }

    return 0;
}