#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    LLI t;
    cin >> t;
    while(t--) {
        LLI n;
        cin >> n;

        string s;
        cin >> s;
        string ans = "";
        char ch = s[n-1];
        for (LLI i=0;i<n;i++) {
            ans += ch;
        }


        cout << ans << "\n";
    }


    return 0;
}
