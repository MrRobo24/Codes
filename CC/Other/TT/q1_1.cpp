#include <bits/stdc++.h>
#define LLI long long 

using namespace std;

int main() {

    LLI t;
    cin >> t;
    while (t--) {
        LLI n, m;
        cin >> n >> m;

        LLI arr[n], brr[m];
        unordered_map<LLI,LLI> mp;
        LLI maxim = INT_MIN;

        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        for (LLI i=0;i<m;i++) {
            cin >> brr[i];
            if (mp[brr[i]] > 0) {
                maxim = max(brr[i], maxim);
            }
        }

        if (maxim == INT_MIN) {
            cout << "No common integer in two arrays.\n";
        } else {
            cout << "The greatest common integer is " << maxim << "\n";
        }
    }
    return 0;
}