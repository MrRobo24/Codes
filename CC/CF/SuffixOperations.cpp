//AC Later - TUT
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI solve(LLI arr[], LLI n) {
    //finding depths and heights
    LLI sum = 0;
    for (LLI i=1;i<n;i++) {
        sum += abs(arr[i] - arr[i-1]);
    }

    LLI sub = max(abs(arr[0] - arr[1]), abs(arr[n-1] - arr[n-2]) );
    for (LLI i=1;i<n-1;i++) {
        sub = max( sub, abs(arr[i] - arr[i-1]) + abs(arr[i+1] - arr[i]) - abs(arr[i+1] - arr[i-1]) );
    }

    return sum - sub;
}

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

        cout << solve(arr, n) << "\n";

    }

    return 0;
}