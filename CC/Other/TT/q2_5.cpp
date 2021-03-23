#include <bits/stdc++.h>
#define LLI long long
#define umap unordered_map
#define uset unordered_set
#define all(v) v.begin(),v.end()
#define loop_arr(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_vec(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_print(arr) for (const auto &i: arr) { cout << i << " ";  } cout << "\n";

using namespace std;

unordered_set<string> dict;
vector<string> ans;
string s;


void solve(LLI r, string curr) {
    if (r == s.size()) {
        ans.push_back(curr);
        return;
    }

    for (const auto &d: dict) {
        string sub = s.substr(r, d.size());
        if (sub == d) {
            solve(r + d.size(), curr + d + " ");
        }
    }

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI nw;
    cin >> nw;
    for (LLI i=0;i<nw;i++) {
        string word;
        cin >> word;
        dict.insert(word);
    }

    cin >> s;

    solve(0, "");

    for (const auto &e: ans) {
        cout << e << "\n";
    }

    return 0;

}