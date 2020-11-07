//AC
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {
    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        LLI arr[n], even = n*2;
        LLI ans[n];
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
            if (i+1 == arr[i]) {
                ans[i] = even;
                even -= 2;
            }
        }
        for (LLI i=0;i<n;i++) {
            ans[i] = ans[arr[i]-1];
        }

        for (LLI i=0;i<n;i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
