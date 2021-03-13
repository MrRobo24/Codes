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

    LLI n, q;
    cin >> n >> q;

    LLI arr[n];
    loop_arr(arr, n);

    // for (const auto &e: arr) {
    //     cout << e << " ";
    // }cout << "\n";

    LLI c = 0;
    for (LLI i=0;i<n;i++) {
        if (arr[i] == 1) {
            c++;
        }
    }

    while (q--) {
        LLI t, x, k;
        cin >> t;
        if (t == 1) {
            cin >> x;
            x--;
            if (arr[x] == 1) {
                c--;
                arr[x] = 0;
            } else {
                c++;
                arr[x] = 1;
            }
        } else {
            cin >> k;
            if (k <= c) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }

    return 0;

}