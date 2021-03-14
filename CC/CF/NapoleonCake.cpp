//AC
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
        LLI n;
        cin >> n;
        LLI arr[n], ans[n];
        loop_arr(arr, n);
        memset(ans, 0, sizeof(ans));
        for (LLI i=0;i<n;i++) {
            ans[i] += arr[i];
        }


        LLI curr = 0;
        LLI out[n];
        memset(out, 0, sizeof(out));

        for (LLI i=n-1;i>=0;i--) {

            curr = max(ans[i], curr);

            if (curr != 0) {
                out[i] = 1;
            }

            curr--;
            
        }

        // loop_print(ans);
        loop_print(out);


    }


    return 0;

}