//AC
#include <bits/stdc++.h>
#define LLI long long 
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    LLI in = 1;
    while (in <= t) {
        LLI n;
        cin >> n;
        LLI mat[n][n];
        for (LLI i=0;i<n;i++) {
            for (LLI j=0;j<n;j++) {
                cin >> mat[i][j];
            }
        }


        LLI k = 0;
        unordered_set<LLI> rows[n];
        unordered_set<LLI> cols[n];
        
        for (LLI i=0;i<n;i++) {
            for (LLI j=0;j<n;j++) {
                rows[i].insert(mat[i][j]);
                cols[j].insert(mat[i][j]);
                if (i == j) {
                    k += mat[i][j];
                }
            }
        }

        LLI r = 0, c = 0;
        for (LLI i=0;i<n;i++) {
            if (rows[i].size() < n) {
                r++;
            }
            if (cols[i].size() < n) {
                c++;
            }
        }

        cout << "Case #" << in << ": " << k << " " << r <<  " " << c << "\n";
        
        in++;
    }


    return 0;
}