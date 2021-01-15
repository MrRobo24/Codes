#include <bits/stdc++.h>
#define LLI long long
using namespace std;

string solve(LLI arr[], LLI n, LLI d) {
    
    vector<LLI> big, small;
    for (LLI i=0;i<n;i++) {
        LLI curr = arr[i];
        if (curr <= d) {
            small.push_back(curr);
        } else {
            big.push_back(curr);
        }
        
    }

    if (big.size() == 0) {
        return "YES";
    }

    if (small.size() <= 1) {
        return "NO\n";
    }

    sort(small.begin(), small.end());
    if (small[0] + small[1] <= d) {
        return "YES";
    }

    return "NO";

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n, d;
        cin >> n >> d;
        LLI arr[n];
        for (LLI i=0;i<n;i++) cin >> arr[i];
        cout << solve(arr, n, d) << "\n";
        

    }

    return 0;
}