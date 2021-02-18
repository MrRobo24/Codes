//AC Later
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

        if (n % 2 == 1) {
            for (LLI i=0;i<n;i++) {
                for (LLI j=i+1, c = 0;j<n;j++, c++) {
                    if (c < n/2) {
                        cout << 1 << " ";
                    } else {
                        cout << -1 << " ";
                    }
                }
            }
        } else {
            for (LLI i=0;i<n;i++) {
                for (LLI j=i+1,c=0;j<n;j++, c++) {
                    if (c < (LLI)(n-2)/2) {
                        cout << 1 << " ";
                    } else if (c > (LLI)(n-2)/2) {
                        cout << -1 << " ";
                    } else {
                        cout << 0 << " ";
                    }
                }
            }
        }

        cout << "\n";
    }

    return 0;
}
