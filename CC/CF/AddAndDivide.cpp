#include <bits/stdc++.h>
#define LLI long long
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI a,b;
        cin >> a >> b;
        LLI m = 1;
        if (b > a) {
            cout << m << "\n";
            continue;
        }
        
        if (b == a) {
            cout << ++m << "\n";
            continue;
        }

        if (b == 1) {
            m++;
            b++;
        }

        LLI t = log2(a)/log2(b);
        // cout << t << "\n";
        m += t;
        a = a / pow(b, t);

        if (b > a) {
            cout << m << "\n";
        } else {
            cout << ++m << "\n";
        }



    }

    return 0;
}
