#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n, m;
        cin >> n;
        LLI r[n];
        for (LLI i=0;i<n;i++) {
            cin >> r[i];
        }
        cin >> m;
        LLI b[m];
        for (LLI i=0;i<m;i++) {
            cin >> b[i];
        }

        LLI pr[n+1], pb[m+1];
        pr[0] = 0;
        pb[0] = 0;
        for (LLI i=0;i<n;i++) {
            pr[i+1] = pr[i] + r[i];
        }
        for (LLI i=0;i<m;i++) {
            pb[i+1] = pb[i] + b[i];
        }

        cout << *max_element(pr, pr+n+1) + *max_element(pb, pb+m+1) << "\n";

    }

    return 0;
}