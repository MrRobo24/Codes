//upsolve
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

v2(LLI) g(1000, v1(LLI)(1000));
v2(LLI) h(1000, v1(LLI)(1000));
v2(LLI) v(1000, v1(LLI)(1000));


void print(LLI t, LLI out) {
    cout << "Case #" << t << ": " << out << "\n";
}


void flipRows(LLI r, LLI c) {
    LLI i, j;
    rep(i, 0, r) {
        rep(j, 0, c/2) {
            swap(g[i][j], g[i][c-j-1]);
        }
    }
}

void flipCols(LLI r, LLI c) {
    LLI i, j;
    rep(j, 0, c) {
        rep(i, 0, r/2) {
            swap(g[i][j], g[r-i-1][j]);
        }
    }
}


void solve() {
    LLI t, tt;
    cin >> t;
    
    rep(tt, 1, t+1) {
        LLI r, c;
        cin >> r >> c;
        
        

        //taking input
        LLI i, j;
        rep(i, 0, r) {
            rep (j, 0, c) {
                cin >> g[i][j];
            }
        }

        // resetting the vectors
        rep(i, 0, r) {
            rep(j, 0, c) {
                h[i][j] = 0;
                v[i][j] = 0;
            }
        }

        
        LLI ans = 0;
        LLI rf, cf;

        rep(cf, 0, 2) {
            rep(rf, 0, 2) {        
               /* calculating he value of left to right row size
                and top to bottom col size for each i,j combination */
                rep(i, 0, r) {
                    rep (j, 0, c) {
                        if (g[i][j]) {
                            h[i][j] = 1 + (j ? h[i][j-1] : 0);
                            v[i][j] = 1 + (i ? v[i-1][j] : 0);
                        } else {
                            h[i][j] = 0;
                            v[i][j] = 0;
                        }
                        // for hor short and ver long
                        ans += max((LLI)0, min(h[i][j], (LLI)v[i][j]/2) - 1 );
                        // for hor long and ver short
                        ans += max((LLI)0, min((LLI)h[i][j]/2, v[i][j]) - 1 );
                    }
                }

                flipRows(r, c);
            }
            flipCols(r, c);
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