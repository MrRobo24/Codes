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
    string s, t;
    fflush(stdin);
    cin >> s;
    fflush(stdin);
    cin >> t;


    vector<pair<LLI, LLI> > idx;
    LLI maxim = INT_MIN, j = 0;
    for (LLI i=0;i<m;i++) {

        while (i > 0 && i < m && t[i] == t[i-1]) {
            idx.push_back(idx[idx.size()-1]);
            i++;
        }

        while (j < n && t[i] != s[j]) {
            j++;
        }

        if (j < n) {
            LLI l = j, r = j;
            while (t[i] == s[j]) {
                j++;
            }
            r = j-1;
            idx.push_back({l,r});
        }
    }

    for (LLI i=0;i<idx.size()-1;i++) {
        maxim = max(maxim, idx[i+1].second - idx[i].first);
    }

    cout << maxim << "\n";


    return 0;

}