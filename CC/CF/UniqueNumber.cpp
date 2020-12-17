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
        LLI x;
        cin >> x;

        if (x > 45) {
            cout << -1 << "\n";
            continue;
        } 

        string ans = "";
        LLI s = 9;

        while (x > 0) {
            if (x < s) {
                s = x;
            }
            x -= s;
            ans = (char)('0' + s) + ans;
            s--;
        }

        cout << ans << "\n";

    }


    return 0;
}