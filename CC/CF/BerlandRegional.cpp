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
        LLI n;
        cin >> n;
        map<LLI, vector<LLI> > data;
        vector<LLI> u(n);
        for (LLI i=0;i<n;i++) {
            cin >> u[i];
        }

        for (LLI i=0;i<n;i++) {
            LLI s;
            cin >> s;
            data[u[i]].push_back(s);
        }

        vector< vector<LLI> > req;
        for (const auto &e: data) {
            req.push_back(e.second);
            sort(req.back().begin(), req.back().end(), greater<LLI>());
        }

        vector< vector<LLI> > pfx(n, vector<LLI>());
        for (LLI i=0;i<req.size();i++) {
            for (LLI j=0;j<req[i].size();j++) {
                if (j == 0) {
                    pfx[i].push_back(req[i][j]);
                } else {
                    pfx[i].push_back(req[i][j] + pfx[i].back());
                }
            }
        }




        // for (LLI i=1;i<=n;i++) {
        //     LLI sum = 0;
        //     for (LLI j=0;j<pfx.size();j++) {
        //         LLI scount = pfx[j].size();
        //         if (scount == 0) {
        //             continue;
        //         }

        //         LLI rev = scount % i;
        //         if (rev > scount-1) {
        //             continue;
        //         }
        //         LLI curr = pfx[j][scount-1-rev];
        //         sum += curr;
        //     }
        //     cout << sum << " ";
        // }

        vector<LLI> ans(n, 0);

        for (const auto &i: pfx) {
            for (LLI j=1;j<=i.size();j++) {
                LLI left = i.size() % j;
                if (left > i.size() - 1) {
                    continue;
                }
                ans[j-1] += i[i.size() - 1 - left];
            }
        }

        for (const auto &e: ans) {
            cout << e << " ";
        }

        cout << "\n";


    }
    
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}