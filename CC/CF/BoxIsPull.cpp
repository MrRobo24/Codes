//AC
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    LLI t;
    cin >> t;
    while (t--) {
        LLI a,b,c,d;
        cin >> a >> b >> c >> d;

        LLI hor = abs(a-c);
        LLI ver = abs(b-d);

        LLI ans = hor + ver;
        if (hor != 0 && ver != 0) {
            ans += 2;
        }

        cout << ans << "\n";

    }

    return 0;
}