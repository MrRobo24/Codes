#include <bits/stdc++.h>
#define LLI int
using namespace std;

LLI dp[1024][1024];

LLI solve(string txt, LLI n, string pat, LLI m) {
    //cout << "X\n";
    if (n < 0 && m < 0) {
      //  cout << "E";
        return 1;
    }

    if (m < 0) {
        //cout << "A";
        return 0;
    }

    if (n < 0) {
        while (m >= 0) {
            if (pat[m] != '*') {
                //cout << "B";
                return 0;
            }
            m--;
        }
        //cout << "C";
        return 1;
    }

    if (dp[n][m] == -1) {
        
        if (pat[m] == '*') {
            return dp[n][m] = solve(txt, n-1, pat, m) ||
                                solve(txt, n, pat, m-1);
        } else {
            if (pat[m] != txt[n] && pat[m] != '?') {
                return dp[n][m] = 0;
            } else {
                return dp[n][m] = solve(txt, n-1, pat, m-1);
            }
        }

    }
    //cout << "D";
    return dp[n][m];

}



int main() {

    string txt,pat;
    cin >> txt;
    cin >> pat;

    memset(dp, -1, sizeof(dp));

    LLI ans  = solve(txt, txt.size()-1, pat, pat.size()-1);
    if (ans) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}