//WA
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI n;

char mat[300][300];
bool visit[300][300];

bool dfs(LLI i, LLI j, LLI c, LLI d) {
    //cout << "CHECK\n";
    if (i < 0 || i > n-1 || j > n-1 || j < 0 ||mat[i][j] == '.' || visit[i][j]) {
        return false;
    }
    
    c++;
    if (c == 3) {
        if (d == 1) {
            mat[i][j+1] = 'O';
            visit[i][j+1] = true;
        } else if (d == 2) {
            mat[i+1][j] = 'O';
            visit[i+1][j] = true;
        } else if (d == 3){
            mat[i][j-1] = 'O';
            visit[i][j-1] = true;
        } else {
            mat[i-1][j] = 'O';
            visit[i-1][j] = true;
        }


        //mat[i][j] = 'O';
        return true;
    } else {
        bool q = dfs(i+1, j, c, 4);
        bool w = dfs(i-1, j, c, 2);
        bool e = dfs(i, j+1, c, 3);
        bool r = dfs(i, j-1, c, 1);
        return q || w || e || r;
    }
    
}


void solve() {
    LLI ans = 0;
    for (LLI i=0;i<n;i++) {
        for (LLI j=0;j<n;j++) {
            //cout << "CHECK " << mat[i][j] == 'X') << " " << visit[i][j] << "\n";
            if (mat[i][j] == 'X' && !visit[i][j]) {
                dfs(i,j,0,0);
            }
        }
    }

    cout << "\n";
    for (LLI i=0;i<n;i++) {
        for (LLI j=0;j<n;j++) {
            cout << mat[i][j] << " ";
            if (mat[i][j] == 'O') {
                ans++;
            }
        }
        cout << "\n";
    }
    cout << "Os " << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI t;
    cin >> t;
    while (t--) {
        cin >> n;
        LLI k = 0;
        for (LLI i=0;i<n;i++) {
            for (LLI j=0;j<n;j++) {
                cin >> mat[i][j];
                if (mat[i][j] == 'X') {
                    k++;
                }
                visit[i][j] = false;
            }
        }
        solve();
        cout << "K " << k << "\n";
    }

    

    return 0;
}