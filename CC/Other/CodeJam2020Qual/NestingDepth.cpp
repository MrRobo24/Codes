//AC
#include <bits/stdc++.h>
#define LLI long long 
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    LLI in = 1;
    while (in <= t) {
        
        string s;
        cin >> s;
        LLI open = 0;
        string ans = "";
        for (const auto &ch: s) {
            LLI curr = ch - '0';
            if (open < curr) {
                while (open < curr) {
                    ans += "(";
                    open++;
                }
                
            } else {
                while (open > curr) {
                    ans += ")";
                    open--;
                }
            }

            ans += ch;
        }

        while (open > 0) {
            ans += ")";
            open--;
        }



        cout << "Case #" << in << ": " << ans << "\n";
        
        in++;
    }


    return 0;
}