#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI w, h, n;
        cin >> w >> h >> n;
        LLI c = 0;
        while (w != 0 && w % 2 == 0) {
            c++;
            w /= 2;
        }

        if (pow(2,c) >= n) {
            cout << "YES\n";
            continue;
        }

        while (h != 0 && h % 2 == 0) {
            c++;
            h /= 2;
        }

        if (pow(2,c) >= n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }

    return 0;
}