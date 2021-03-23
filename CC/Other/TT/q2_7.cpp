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

    LLI n,k;
    cin >> n >> k;

    vector<LLI> arr(n);
    loop_vec(arr, n);

    unordered_map<LLI, LLI> mp;
    for (const auto &e: arr) {
        mp[e]++;
    }

    for (const auto &e: arr) {
        if (mp[e] > 0 && mp[k-e] > 0) {
            
            if (e*2 == k && mp[e] >= 2) {
                cout << e << ", " << e << "\n";
                mp[e]-=2;
                continue;
            }

            mp[e]--;
            mp[abs(k-e)]--;

            cout << e << ", " << k-e << "\n";
        }
    }


    return 0;

}