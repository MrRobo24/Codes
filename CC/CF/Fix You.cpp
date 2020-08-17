#include <bits/stdc++.h>
#define LLI long long int

using namespace std;

LLI n,m;

LLI func(vector< vector<char> > mat, LLI i, LLI j) {
    if (i > n || j > m) {
        return 0;
    }

    if (i >= n-1 && j >= m-1) {
        return 0;
    }


    if (i == n-1 && mat[i][j] == 'D') {
        mat[i][j] = 'R';
        return 1 + func(mat, i, j + 1);
    } else if (j == m-1 && mat[i][j] == 'R') {
        mat[i][j] = 'D';
        return 1 + func(mat, i+1, j);
    }

    char ch = mat[i][j];
    int nexti, nextj;
    if (ch == 'D') {
        nexti = i+1;
        nextj = j;
    } else {
        nexti = i;
        nextj = j+1;
    }

    int leave = func(mat, nexti, nextj);
    if (ch == 'D') {
        mat[i][j] = 'R';
        nexti = i;
        nextj = j + 1;
    } else {
        mat[i][j] = 'D';
        nexti = i + 1;
        nextj = j;
    }
    int change = 1 + func(mat,nexti, nextj);

    return min(leave, change);

}





int main() {
    LLI t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vector< vector<char> > mat(n, vector<char>(m));
        for (LLI i=0;i<n;i++) {
            for (LLI j=0;j<m;j++) {
                cin >> mat[i][j];
            }
        }

        cout << func(mat, 0, 0) << "\n";


    }
}
