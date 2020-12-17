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

        if (n < 4) {
            cout << "NO\n";
            continue;
        } 

        string pat = "2020";
        LLI idx = 0, i=0;
        while (i<n && idx < 4 && s[i] == pat[idx]) {
            i++;
            idx++;
        }

        if (idx == 4) {
            cout << "YES\n";
            continue;
        }

        i = n - (4 -idx);

        while (i<n && idx < 4 && s[i] == pat[idx]) {
            i++;
            idx++;
        }

        if (idx == 4) {
            cout << "YES\n";
            continue;
        }
        
        cout << "NO\n";
    }


    return 0;
}