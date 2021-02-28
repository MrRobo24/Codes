#include <bits/stdc++.h>
#define LLI long long

using namespace std;

int main() {

    LLI t;
    cin >> t;
    while (t--) {
        LLI n, k;
        cin >> n >> k;

        LLI arr[n];
        unordered_map<LLI, LLI> count;
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
            count[arr[i]]++;
        }

        for (LLI i=0;i<n;i++) {
            LLI l = k - arr[i];
            if (l != arr[i]) {
                if (count[l] > 0) {
                    cout << "(" << arr[i] << ", " << l << ")\n";
                    count[l]--;
                    count[arr[i]]--;
                }
            } else {
                if (count[l] > 1) {
                    cout << "(" << arr[i] << ", " << arr[i] << ")\n";
                    count[arr[i]]-=2;
                }
            }
        }

    }


    return 0;
}