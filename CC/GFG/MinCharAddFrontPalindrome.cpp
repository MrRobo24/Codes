#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI solve(string s) {
    LLI n = s.size();

    if (n == 1) {
        return 0;
    }

    if (n == 2 && s[0] != s[1]) {
        return 1;
    }

    LLI m = n/2;
    while (m > 0) {
        LLI flag = 1;

        while (m >= 1 && s[m-1] != s[m+1] && s[m-1] != s[m]) {
            m--;
        }

        if (m > 0) {
            for (LLI i=m-1;i>0;i--) {
                if (s[i] != s[i-1] && s[i] != s[2*m-i]) {
                    m = i;
                    flag = 0;
                    break;
                }
            }
        }

        if (flag == 1) {
            break;
        } 
    }
    
    if (m == 0 || s[m-1] == s[m+1])
        return (n-1) - 2*m;
    else
        return n - 2*m;

}

int main() {
    string s;
    cin >> s;

    cout << solve(s) << "\n";
}