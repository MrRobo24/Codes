#include <bits/stdc++.h>
#define LLI long long
using namespace std;


void solve(vector< vector<string> > &mat, LLI row, string ans) {
    if (row == mat.size()) {
        cout << ans << "\n";
        return;
    }

    for (LLI j=0;j<mat[row].size();j++) {
        solve(mat, row+1, ans + " " + mat[row][j]);
    }
}


int main() {
    LLI n, m;
    cout << "Enter the number of rows: ";
    cin >> n;

    vector < vector<string> > mat(n);
    for (LLI i=0;i<n;i++) {
        cout << "Enter the number of words in row " << i << ": ";
        cin >> m;
        cout << "Enter the words: ";
        for(LLI j=0;j<m;j++) {
            string val;
            cin >> val;
            mat[i].push_back(val);
        }
    }


    cout << "Solving....\n";
    solve(mat, 0, "");


    return 0;
}