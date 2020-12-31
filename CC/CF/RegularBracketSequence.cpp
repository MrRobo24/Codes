#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        LLI n = s.size();
        if (n % 2 != 0) {
            cout << "NO\n";
        } else if (s[0] == ')' || s[n-1] == '(') {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }



    return 0;
}