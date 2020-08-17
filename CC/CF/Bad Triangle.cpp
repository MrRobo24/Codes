#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

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

        if (arr[0] + arr[1] <= arr[n-1]) {
            cout << "1 2 " << n << "\n";
        } else {
            cout << -1 << "\n";
        }

    }


    return 0;
}
