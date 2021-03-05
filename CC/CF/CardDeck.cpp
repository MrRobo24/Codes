#include <bits/stdc++.h>
#define LLI long long
#define umap unordered_map
#define uset unordered_set
#define all(v) v.begin(),v.end()
#define loop_arr(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_vec(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_print(arr) for (const auto &i: arr) { cout << i << " ";  } cout << "\n";

using namespace std;

LLI solve(LLI n, LLI p) {

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
       LLI n;
       cin >> n;
       LLI arr[n];
       loop_arr(arr, n)

       vector<LLI> idx;
       LLI maxim = INT_MIN;
       for (LLI i=0;i<n;i++) {
           if (maxim < arr[i]) {
               maxim = arr[i];
               idx.push_back(i);
           }
       }

       LLI i = idx.size()-1;
       LLI s = idx[i], e = n;

       while (i >= 0) {
           s = idx[i];
           for (LLI j=s;j<e;j++) {
               cout << arr[j] << " ";
           }
           e = s;
           i--;
       }
       cout << "\n";
    }

    return 0;

}