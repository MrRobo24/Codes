//AC Later
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
        vector<LLI> w(n);
        vector<LLI> count(n+1, 0);
        for (LLI i=0;i<n;i++) {
            cin >> w[i];
            count[w[i]]++;
        }

        LLI ans = INT_MIN;

        for (LLI s=2;s<=2*n;s++) {

            LLI c = 0;

            for (LLI i=1;i<(LLI)(s+1)/2;i++) {
                if (s - i <= n) {
                    c += min(count[s-i], count[i]);
                }
            }

            if (!(s & 1)) {
                c += (LLI)count[(s/2)]/2;
            }

            ans = max(ans, c);
        }

        cout << ans << "\n";

    }
}

