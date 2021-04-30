//AC Later
#include <bits/stdc++.h>
#define LLI long long
#define MOD 1000000007
#define umap unordered_map
#define uset unordered_set
#define all(v) v.begin(),v.end()
#define loop_arr(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_vec(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_print(arr) for (const auto &i: arr) { cout << i << " ";  } cout << "\n";
#define rep(i, start, end) for (i=start;i<end;i++)
#define repn(i, start, end) for (i=start;i>=end;i--)
#define v1(T) vector<T>
#define v2(T) vector< vector<T> > 

using namespace std;

void solve() {
    
    LLI t;
    cin >> t;
    while (t--) {
        LLI n, m, k;
        cin >> n >> m >> k;
        vector< vector<LLI> > grid(n, vector<LLI>(m, 0));
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                if (i==0) {
                    grid[i][j] = 1 + grid[i][j-1];
                    continue;
                }

                if (j == 0) {
                    grid[i][j] = 1 + grid[i-1][j];
                    continue;
                }

                grid[i][j] = grid[i][j-1] + (i+1);
            }
        }

        if (grid[n-1][m-1] == k) {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";

    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}