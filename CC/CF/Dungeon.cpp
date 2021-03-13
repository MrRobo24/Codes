//WA
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI a, b, c;
        cin >> a >> b >> c;
        if ((a + b + c) % 9 != 0) {
            cout << "NO\n";
        } else {
            LLI k = (a + b + c) / 9;
            if (a >= k && b >= k && c >= k) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }

    }


    return 0;
}