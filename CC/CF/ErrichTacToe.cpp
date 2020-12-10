//AC Later
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI n;

char mat[300][300];

void solve() {
    LLI color[] = {0, 0, 0};
    for (LLI i=0;i<n;i++) {
        for (LLI j=0;j<n;j++) {
            if (mat[i][j] == 'X') {
                color[(i+j)%3]++;
            }
        }
    }

    LLI idx = 2;
    if (color[0] <= color[1] && color[0] <= color[2]) {
        idx = 0;
    } else if (color[1] <= color[0] && color[1] <= color[2]) {
        idx = 1;
    }

    for (LLI i=0;i<n;i++) {
        for (LLI j=0;j<n;j++) {
            if (mat[i][j] == 'X' && (i+j)%3 == idx) {
                mat[i][j] = 'O';
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