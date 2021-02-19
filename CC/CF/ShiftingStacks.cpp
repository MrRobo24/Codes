//AC
#include <bits/stdc++.h>
#define LLI long long
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        LLI arr[n];
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
        }

        if (n == 1) {
            cout << "YES\n";
            continue;
        }

        LLI e = 0;
        for (LLI i=0;i<n;i++) {
            if (arr[i] > i) {
                e += arr[i] - i;
            } else if (arr[i] < i) {
                if (arr[i] + e < i) {
                    e = -1; 
                    cout << "NO\n"; 
                    break;
                } else {
                    e -= (i - arr[i]);
                }
            }
        }

        if (e != -1) {
            cout << "YES\n";
        }

    }

    return 0;
}
