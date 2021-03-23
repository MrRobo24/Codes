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

    LLI t, tt = 1;
    cin >> t;
    while (tt <= t) {
        LLI n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        
        int curr = 0;
        int l = 0, r = n-1;
        while (l <= r) {
            if (s[l] != s[r]) {
                curr++;
            }
            
            l++;
            r--;
        }
        
        cout << "Case #" << tt << ": ";
        if (curr == k) {
            cout << 0;
        } else {
            cout << abs(k-curr);
        }
        
        cout << "\n";
        tt++;
    }

    

    return 0;

}