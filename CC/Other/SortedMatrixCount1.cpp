//AC Later
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

void printMat(vector< vector<LLI> > mat, LLI n) {
    cout << "Input Matrix:\n";
    for (LLI i=0;i<n;i++) {
        for (LLI j=0;j<n;j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

void solve(vector< vector<LLI> > mat, LLI n) {
    LLI left = 0, right = n-1, count = 0;
    for (LLI i=0;i<n;i++) {
        left = 0;
        while (left <= right) {
            LLI mid = left + (right-left)/2;
            if (mat[i][mid]) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        if (right < 0) {
            if (mat[i][left]) {
                count += n - left;
            }
        } else {
            if (mat[i][right]) {
                count += n - right;
                right--;
            } else if (mat[i][left]) {
                count += n - left;
            }
        }

    }

    cout << "COUNT: " << count << "\n\n";
}


int main() {    
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        vector< vector<LLI> > mat(n);
        for (LLI i=0;i<n;i++) {
            for (LLI j=0;j<n;j++) {
                LLI val;
                cin >> val;
                mat[i].push_back(val);
            }
        }

        printMat(mat, n);
        solve(mat, n);
    }

    return 0;
}