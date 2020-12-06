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
        LLI arr[n], up = 0;
        vector<LLI> ans;
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
        }
        if (arr[0] != arr[1])
            ans.push_back(arr[0]);

        if (arr[1] > arr[0]) {
            up = 1;
        } else {
            up = 0;
        }

        for (LLI i=1;i<n-1;i++) {
            if (!up && arr[i+1] > arr[i]) {
                up = 1;
                ans.push_back(arr[i]);
            } else if (up && arr[i+1] < arr[i]) {
                up = 0;
                ans.push_back(arr[i]);
            }
        }

        ans.push_back(arr[n-1]);

        cout << ans.size() << "\n";
        for (LLI i=0;i<ans.size();i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";

    }

    return 0;
}