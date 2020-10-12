#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI lengthLongestCommonSubstring(string a, string b) {
    LLI n = a.size();
    LLI m = b.size();

    LLI t[n+1][m+1];
    for (LLI i=0;i<n+1;i++)
        t[i][0] = 0;
    for (LLI j=0;j<m+1;j++)
        t[0][j] = 0;
    

    for (LLI i=1;i<n+1;i++) {
        for (LLI j=1;j<m+1;j++) {
            if (a[i-1] == b[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            } else {
                t[i][j] = 0;
            }
        }
    }

    LLI maxim = INT_MIN;
    for (LLI i=1;i<n+1;i++) {
        for (LLI j=1;j<m+1;j++) {
            maxim = max(maxim, t[i][j]);
        }
    }

    return maxim;
}

int main() {

    string a,b;
    cin >> a;
    cin >> b;

    cout << lengthLongestCommonSubstring(a,b) << "\n";



    return 0;
}