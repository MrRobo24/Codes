//AC Later
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI solve(LLI* arr, LLI n, LLI x) {
    if (n == 1) {
        return 0;
    }
    LLI ans = 0;

    LLI keep = n-2;

    while ( keep >= 0 && arr[keep] <= arr[keep + 1]) {
        keep--;
    }
    keep++;
    
    for (LLI i=0;i<n;i++) {

        if (i == keep) {
            break;
        }

        if (arr[i] > x) {
            LLI t = x;
            x = arr[i];
            arr[i] = t;
            ans++;
        }

        if (i != n-1 && arr[i] > arr[i+1]) {
            return -1;
        }
    }

    return ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI t;
    cin >> t;
    while (t--) {
        LLI n, x;
        cin >> n >> x;
        LLI arr[n];
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
        }

        cout << solve(arr, n, x) << "\n";
    }

    return 0;
}