#include <bits/stdc++.h>
#define LLI int64_t
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        LLI lim = n/2020;
        for (LLI i=0;i<=lim;i++) {
            if ((n - 2020 * i) % 2021 == 0) {
                n = -1;
                break;
            }
        }

        if (n == -1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }


    return 0;
}