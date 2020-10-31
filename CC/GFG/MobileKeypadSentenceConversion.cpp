#include <bits/stdc++.h>
#define LLI long long
using namespace std;

string convert(string s) {
    LLI n = s.size();
    string ans = "";
    for (LLI i=0;i<n;i++) {
        char ch = s[i];
        if (ch == ' ') {
            ans += "0";
            continue;
        }

        if (ch <='O') {
            
            LLI c = (1 + (ch - 'A') % 3);
            char num =  (char)(2 + (ch - 'A')/3 + '0') ;    
            while (c--) {
                ans += num;
            }
            
        } else if (ch < 'T') {
            LLI c = (ch - 'P') + 1;
            while (c--) {
                ans += "7";
            }
        } else if (ch > 'V') {
            LLI c = (ch - 'W') + 1;
            while (c--) {
                ans += "9";
            }
        } else {
            LLI c = (ch - 'T') + 1;
            while (c--) {
                ans += "8";
            }
        }
    }

    return ans;
}


int main() {

    string s;
    getline(cin,s);
    cout << convert(s) << "\n";
    return 0;
}