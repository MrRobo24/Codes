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

        LLI ans[n];
        ans[n-1] = arr[n-1];

        for (LLI i=n-2;i>=0;i--) {
            if (i + arr[i] < n) {
                ans[i] = arr[i] + ans[i+arr[i]];
            } else {
                ans[i] = arr[i];
            }
        }

        cout << *max_element(ans, ans+n) << "\n";
        
    }

    return 0;
}