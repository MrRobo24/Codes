//WA
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n, m;
        cin >> n >> m;
        LLI mat[n][n];
        vector<LLI> xrr;
        vector<LLI> yrr;

        memset(mat, 0, sizeof(mat));
        for (LLI i=0;i<m;i++) {
            LLI x, y;
            cin >> x >> y;
            xrr.push_back(x-1);
            yrr.push_back(y-1);
            mat[x-1][y-1] = 1;
        }

        for (LLI i=0;i<n;i++) {
            for (LLI j=0;j<n;j++) {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
        
        LLI steps = 0;
        for (LLI i=0;i<m;i++) {
            LLI x, y;
            x = xrr[i];
            y = yrr[i];

            if (mat[x][y] && x != y) {
                steps++;
                if (mat[y][x] == 1) {
                    steps += 2;
                    mat[y][x] = 0;
                }
                
            }
        }

        cout << steps << "\n";
    }

    return 0;
}