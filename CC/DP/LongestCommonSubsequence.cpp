#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI t[10000][10000];

void printLCS(string a, string b) {
    LLI i = a.size();
    LLI j = b.size();
    stack <char> ans;
    while (i > 0 && j > 0) {
        //cout << i << " " << j << "\n";
        if (a[i-1] == b[j-1]) {
            ans.push(a[i-1]);
            i--;
            j--;
        } else {
            if (t[i-1][j] > t[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    cout << "Longest Common Subsequence is: ";

    while(!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
    cout << "\n";
}


LLI lengthLongestCommonSubsequence(string a, string b) {
    LLI n = a.size(), m = b.size();

    for (LLI i=0;i<n+1;i++)
        t[i][0] = 0;
    for (LLI j=1;j<m+1;j++)
        t[0][j] = 0;

    for (LLI i=1;i<n+1;i++) {
        for (LLI j=1;j<m+1;j++) {
            if (a[i-1] == b[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            } else {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    return t[n][m];
}

int main() {

    string a,b;
    cout << "Enter the first string: ";
    cin >> a;
    cout << "Enter the second string: ";
    cin >> b;

    cout << lengthLongestCommonSubsequence(a,b) << "\n";
    printLCS(a, b);

    return 0;
}