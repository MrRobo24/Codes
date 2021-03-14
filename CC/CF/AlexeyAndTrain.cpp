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
        LLI a[n], b[n], tm[n];
        for (LLI i=0;i<n;i++) {
            cin >> a[i] >> b[i];
        }

        loop_arr(tm, n);

        LLI curr = 0;
        LLI prevb = 0;
        for (LLI i=0;i<n;i++) {
            // cout << a[i] << " " << b[i] << "\n";
            curr += a[i] - prevb + tm[i];
            prevb = b[i];
            // cout << "arrival " << curr << "\n";
            if (i == n-1) {
                break;
            }

             curr +=  ceil((double)(b[i]-a[i])/2);

            if (curr < b[i]) {
                // cout << "CHANGE\n";
                curr = b[i];
            }

            // cout << "departure " << curr << "\n";

        }

        cout << curr << "\n";

    }

    return 0;

}

/*
1
2
2 4
10 12
0 2


*/