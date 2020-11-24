
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    LLI n = s.size(), j=0;
    string s2 = "hello";
    for (LLI i=0;i<n;i++) {
        if (s[i] == s2[j]) {
            j++;
        }
    }

    if (j == 5) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}