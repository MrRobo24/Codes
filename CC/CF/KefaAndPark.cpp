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
LLI n, m;
vector<LLI> graph[100000];
vector<LLI> cats;


void dfs(LLI u, LLI prev, LLI &ans, LLI count) {

    // cout << u+1 << " " << count <<   "\n";

    if (count > m) {
        return;
    }

    bool leaf = true;


    for (const auto &v: graph[u]) {

        if (v == prev) {
            continue;
        }

        leaf = false;


        dfs(v, u, ans, count * cats[v] + cats[v]);
    }

    ans += leaf;

}

LLI solve() {
    LLI ans = 0;
    dfs(0, -1, ans, cats[0]);
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (LLI i=0;i<n;i++) {
        LLI val;
        cin >> val;
        cats.push_back(val);
    }
    
    for (LLI i=0;i<n-1;i++) {
        LLI x, y;
        cin >> x >> y;
        x--;y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cout << solve() << "\n";




    return 0;

}