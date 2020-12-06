#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI solve(LLI* ver, LLI* hor, LLI n, LLI m) {

    LLI c = 0;

    for (LLI i=0;i<n;i++) {
        for (LLI j=0;j<m;j++) {
            if (ver[i] == hor[j]) {
                c++;
                break;
            }
        }
    }

    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI t;
    cin >> t;
    while (t--) {
        LLI n, m;
        cin >> n >> m;
        LLI ver[n], hor[m];

        for (LLI i=0;i<n;i++) {
            cin >> ver[i];
        }

        for (LLI i=0;i<m;i++) {
            cin >> hor[i];
        }

        cout << solve(ver, hor, n, m) << "\n";

    }

    return 0;
}