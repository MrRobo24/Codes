#include <bits/stdc++.h>
#define LLI long long
using namespace std;


LLI n;

LLI dfs(vector< vector<LLI> > mat, LLI a, LLI b) {
    if (a >= n || b >= n || mat[a][b] == -1 || mat[a][b] == 0) {
        return 0;
    }

    mat[a][b] = -1;
    return 1 + max(dfs(mat, a+1, b), dfs(mat, a, b+1));
}


int main() {
    
    cin >> n;
    vector< vector<LLI> > mat(n);
    for (LLI i=0;i<n;i++) {
        for (LLI j=0;j<n;j++) {
            LLI val;
            cin >> val;
            mat[i].push_back(val);
        }
    }


    LLI maxim = INT_MIN;
    for (LLI i=0;i<n;i++) {
        for (LLI j=0;j<n;j++) {
            maxim = max(dfs(mat, i, j), maxim);
        }
    }

    if (maxim == INT_MIN) {
        cout << "No path available\n";
    } else {
        cout << "The length of longest path is " << maxim << "\n";    
    }

    

    return 0;
}