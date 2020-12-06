#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI t;
    cin >> t;
    while (t--) {
        LLI n, c= 0;
        cin >> n;
        string s;
        cin >> s;
        for (LLI i=0;i<n;i++) {
            if (s[i] == 't') {
                c++;
            }
        }

        
        string ans = "";
        for (LLI i=0;i<n;i++) {
            if (s[i] != 't') {
                ans += s[i];
            }
        }

        while (c--) {
            ans += 't';
        }

        cout << ans << "\n";

    }

    return 0;
}