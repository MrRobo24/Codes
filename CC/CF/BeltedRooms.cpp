//WA
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        string s;
        cin >> s;
        char ch = s[0];
        LLI count = 1;
        for (LLI i=1;i<s.size();i++) {
            if (ch == s[i] || s[i] == '-' || ch == '-') {
                count++;
            }
            ch = s[i];
        }

        if (count == 1) {
            cout << 0 << "\n";
        } else {
            cout << count << "\n";
        }
        

    }

    return 0;
}