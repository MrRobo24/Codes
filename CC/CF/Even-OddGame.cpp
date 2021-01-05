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
        vector<LLI> arr;
        for (LLI i=0;i<n;i++) {
            LLI val;
            cin >> val;
            arr.push_back(val);
        }

        sort(arr.rbegin(), arr.rend());
        LLI score = 0;
        for (LLI i=0;i<n;i++) {
            if (i % 2 == 0) {
                if (arr[i] % 2 == 0) {
                    score += arr[i];
                }
            } else {
                if (arr[i] % 2 != 0) {
                    score -= arr[i];
                }
            }
        }

    
        if (score > 0) {
            cout << "Alice\n";
        } else if (score < 0) {
            cout << "Bob\n";
        } else {
            cout << "Tie\n";
        }
    }

    return 0;
}