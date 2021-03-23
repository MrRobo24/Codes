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

    LLI n, m;
    cin >> n >> m;

    vector<LLI> arr(n);
    vector<LLI> brr(n);

    loop_vec(arr, n);
    loop_vec(brr, m);

    umap<LLI, LLI> mp;
    for (const auto &e: brr) {
        mp[e]++;
    }


    vector<LLI> ans;
    for (const auto &e: arr) {
        while (mp[e]) {
            ans.push_back(e);
            mp[e]--;
        }
    }

    for (const auto &e: ans) {
        cout << e << " ";
    }



    return 0;

}