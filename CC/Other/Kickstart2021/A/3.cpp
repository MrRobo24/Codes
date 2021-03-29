#include <bits/stdc++.h>
#define LLI long long
#define umap unordered_map
#define uset unordered_set
#define all(v) v.begin(),v.end()
#define loop_arr(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_vec(arr, n) for (LLI i=0;i<n;i++) {cin >> arr[i];}
#define loop_print(arr) for (const auto &i: arr) { cout << i << " ";  } cout << "\n";
#define rep(i, start, end) for (i=start;i<end;i++)
#define v1(T) vector<T>
#define v2(T) vector< vector<T> > 

using namespace std;

v2(LLI) g(300, v1(LLI)(300) );
LLI ans = 0;
LLI r, c;

void print(LLI t, LLI out) {
    cout << "Case #" << t << ": " << out << "\n";
}

void travel(LLI i, LLI j) {

    if (i < 0 || i >= r || j < 0 || j >= c) {
        return;
    }

    if (i && g[i-1][j] < g[i][j]) {
        if (g[i][j] - g[i-1][j] > 1) {
            ans += (g[i][j] - 1) - g[i-1][j];
            g[i-1][j] = g[i][j]-1;
            
        }
    }

    if (i < r-1 && g[i+1][j] < g[i][j]) {
        if (g[i][j] - g[i+1][j] > 1) {
            ans += (g[i][j] - 1) - g[i+1][j];
            g[i+1][j] = g[i][j]-1;
        }
    }

    if (j && g[i][j-1] < g[i][j]) {
        if (g[i][j] - g[i][j-1] > 1) {
            ans += (g[i][j] - 1) - g[i][j-1];
            g[i][j-1] = g[i][j]-1;
        }
    }

    if (j < c-1 && g[i][j+1] < g[i][j]) {
        if (g[i][j] - g[i][j+1] > 1) {
            ans += (g[i][j] - 1) - g[i][j+1];
            g[i][j+1] = g[i][j]-1;
        }
    }



    travel(i-1, j);
    travel(i+1, j);
    travel(i, j-1);
    travel(i, j+1);


}


void solve() {
    LLI t, tt;
    cin >> t;
    
    rep(tt, 1, t+1) {
        cin >> r >> c;

        LLI i,j;
        ans = 0;

        rep(i, 0, r) {
            rep(j, 0, c) {
                cin >> g[i][j];
            }
        }
        
        rep (i, 0, r) {
            rep (j, 0, c) {
                if (i && g[i-1][j] >= g[i][j]) {
                    continue;
                }

                if (i < r-1 && g[i+1][j] >= g[i][j]) {
                    continue;
                }

                if (j && g[i][j-1] >= g[i][j]) {
                    continue;
                }

                if (j < c-1 && g[i][j+1] >= g[i][j]) {
                    continue;
                }

                travel(i, j);
            }
        }

        print(tt, ans);

        
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}