#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n, c0, c1, h;
        string s;
        cin >> n >> c0 >> c1 >> h;
        cin >> s;
        LLI one = 0, zero = 0;
        for (LLI i=0;i<n;i++) {
            if (s[i] == '1') {
                one++;
            } else {
                zero++;
            }
        }

        LLI a = (zero * c0) + (one * c1);
        LLI b = (zero * h) + ((one + zero) * c1);
        LLI c = ((zero + one) * c0) + (one * h);

        cout << min(a, min(b, c)) << "\n";
    }
}