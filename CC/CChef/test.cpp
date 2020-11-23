#include <bits/stdc++.h>
#define LLI long long int
using namespace std;
int main() {

    LLI t;
    cin >> t;

    while (t--) {
        LLI n, ans = 1;
        cin >> n;
        string s;
        cin >> s;
        
        LLI zero = 0, one = 0;
        string comp = "";
        for (LLI i=0;i<n;i++) {
            char ch = s[i];
            if (ch == '0') {
                if (comp[comp.size()-1] == '0') {
                    zero++;
                } else if ((i+1 < n && s[i+1] == '1') ||
                    (i-1>=0 && s[i-1] == '1') ) {
                    comp += ch;
                    continue;
                } else {
                    zero++;
                }
            } else {

                if (comp[comp.size()-1] == '1') {
                    one++;
                } else if ((i+1 < n && s[i+1] == '0') ||
                    i-1 >=0 && s[i-1] == '0') {
                        comp += ch;
                        continue;
                } else {
                    one++;
                }
            }
        }

        // if (zero == one) {
        //     ans += zero;
        // } else {
        //     ans += max(zero, one);
        // }
        if (zero + one == n) {
            cout << n << "\n";
        } else {
            cout << ans + max(zero, one) << "\n";
        }
        
    }

    return 0;
}