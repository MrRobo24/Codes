//AC Later
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        while (q--) {
            LLI l, r;
            cin >> l >> r;
            l--;
            r--;
            char a = s[l];
            char b = s[r];
            LLI flag = 0;
            for (LLI i=0;i<l;i++) {
                if (s[i] == a) {
                    flag = 1;
                    break;
                }
            }

            for (LLI i=n-1;i>r;i--) {
                if (s[i] == b) {
                    flag = 1;
                    break;
                }
            }

            if (flag) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }

        }

    }

    return 0;
}