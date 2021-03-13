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

        string s;
        cin >> s;

        if (k == 0) {
            cout << "YES\n";
            continue;
        }

        if (n < k * 2 + 1) {
            cout << "NO\n";
            continue;
        }

        LLI i = 0, j = n-1, flag = 1;
        while (i < k) {
            if (s[i] != s[j]) {
                flag = 0;
                break;
            }
            i++;
            j--;
        }

        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }



    }
    

    return 0;

}