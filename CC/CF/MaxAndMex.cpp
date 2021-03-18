#include <bits/stdc++.h>
#define LLI long long
#define umap unordered_map
#define uset unordered_set
#define all(v) v.begin(),v.end()
#define loop_arr(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_vec(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_print(arr) for (const auto &i: arr) { cout << i << " ";  } cout << "\n";

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n, k;
        cin >> n >> k;
        set<LLI> arr;
        for (LLI i=0;i<n;i++) {
            LLI val;
            cin >> val;
            arr.insert(val);
        }

        LLI mex = 0, maxim = INT_MIN;
        for (auto &i: arr) {
            // cout << i << "\n";
            if (i <= mex) {
                mex++;
            }

            if (i > maxim) {
                maxim = i;
            }
        }

        LLI count = n;

        // cout << mex << " " << maxim << "\n";

        if (mex > maxim) {
            count = n + k;
        } else {
            if (k > 0) {
                LLI e = ceil((double)(mex + maxim) / 2);
                if (arr.find(e) == arr.end()) {
                    count++;
                }
            }
            
        }

        

        cout << count << "\n";
        
    }

    return 0;

}