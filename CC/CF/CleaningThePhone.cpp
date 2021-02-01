//WA got the question wrong
#include <bits/stdc++.h>
#define LLI int64_t
#define LLD long double
using namespace std;

LLI dp[200001][1000000001];
LLI solve(LLI a[], LLI p[], LLI n, LLI m) {
    if (n <= 0 || m <= 0) {
        return 0;
    }

    if (dp[n][m] != -1) {
        return dp[n][m];
    }

    return dp[n][m] = min( p[n-1] + solve(a, p, n-1, m-a[n-1]), 
                                solve(a, p, n-1, m) );

}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n, m;
        cin >> n >> m;

        LLI a[n], p[n], tot = 0;
        LLD r[n];
        for (LLI i=0;i<n;i++) {
            cin >> a[i];
            tot+=a[i];
        }
        for (LLI i=0;i<n;i++) {
            cin >> p[i];
            r[i] = (LLD)a[i]/p[i];
        }

        if (m > tot) {
            cout << -1 << "\n";
            continue;
        }

        cout << solve(a, p, n, m) << "\n";

    }


    return 0;
}