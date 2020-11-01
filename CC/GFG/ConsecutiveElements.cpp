#include <iostream>
#define LLI long long
using namespace std;

string solve(string s, LLI n) {
    
    if (n < 0) {
        return "";
    } 
    string ret = solve(s, n-1);
    if (s[n]  == ret[ret.size()-1]) {
        return ret;
    } else {
        return ret + s[n];
    }
}



int main() {
    
    LLI t;
    cin >> t;
    while (t--) {
        string s;
        string ans = "";
        cin >> s;
        LLI n = s.size();
/*
        if (n == 1) {
            cout << s << "\n";
            continue;
        }
        
        for (LLI i=0;i<n-1;i++) {
            if (s[i] != s[i+1]) {
                ans += s[i];
            }
        }
        
        ans += s[n-1];
        cout << ans << "\n";
        */
        cout << solve(s, n-1) << "\n";
    }

	return 0;
}