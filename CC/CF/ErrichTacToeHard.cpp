//AC
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI n, k;
char mat[300][300];
void solve() {
    k = 0;
    LLI colorX[] = {0, 0, 0};
    LLI colorO[] = {0, 0, 0};

    for (LLI i=0;i<n;i++) {
        for (LLI j=0;j<n;j++) {
            if (mat[i][j] == 'X') {
                colorX[(i+j)%3]++;
                k++;
            } else if (mat[i][j] == 'O') {
                colorO[(i+j)%3]++;
                k++;
            }
        }
    }

    LLI mX = 0, mO = 0;
    for (LLI i=0;i<3;i++) {
        for (LLI j=0;j<3;j++) {
            if (i != j) {
                if (colorX[i] + colorO[j] <= (k/3)) {
                    mX = i;
                    mO = j;
                    break;
                }
            }
        }
    }

    // cout << "CHECK\n";
    // cout << mX << " " << mO << "\n";

    for (LLI i=0;i<n;i++) {
        for (LLI j=0;j<n;j++) {

            if (mat[i][j] == 'X' && (i+j)%3 == mX) {
                mat[i][j] = 'O';
            } else if(mat[i][j] == 'O' && (i+j)%3 == mO) {
                mat[i][j] = 'X';
            }

            cout << mat[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (LLI i=0;i<n;i++) {
            for (LLI j=0;j<n;j++) {
                cin >> mat[i][j];
            }
        }
        solve();
    }

    

    return 0;
}