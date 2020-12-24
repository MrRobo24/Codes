//AC
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        string s;
        cin >> s;

        LLI i=n-1, c = 0;
        while (i >= 0 && s[i] == ')' && c <= n/2) {
            c++;
            i--;
        }

        if (c > n/2) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }

    }

    return 0;
}