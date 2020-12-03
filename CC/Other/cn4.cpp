#include <bits/stdc++.h>
#define LLI long long
using namespace std;
LLI c = 0,n;
LLI mat[1000][1000];
LLI v[1000][1000];

LLI dfs(LLI i, LLI j) {
    c++;
    v[i][j] = 1;

    if (i > 0 && mat[i-1][j]) {
        dfs(i, j);
    }

    if (j > 0 && mat[i][j-1]) {
        dfs(i, j);
    }

    if (i < n-1) {
        dfs(i+1, j);
    }

    if (j < n-1) {
        dfs(i, j+1);
    }
}

int main() {
    LLI t;
    cin >> t;
    while (t--) {
        cin >> n;
        
        for (LLI i=0;i<n;i++) {
            for (LLI j=0;j<n;j++) {
                cin >> mat[i][j];
            }
        }

        LLI p;
        cin >> p;

        memset(v,0, sizeof(v));

        map<LLI, pair<LLI,LLI> > data;

        for (LLI i=0;i<n;i++) {
            for (LLI j=0;j<n;j++) {
                if (!v[i][j] && mat[i][j]) {
                    c = 0;
                    dfs(i,j);
                    data[c] = {i,j};
                }
            }
        }

        

    }
    return 0;
}