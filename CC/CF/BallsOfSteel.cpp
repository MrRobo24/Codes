#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI t;
    cin >> t;
    while (t--) {
        LLI n, k;
        cin >> n >> k;

        LLI x[n], y[n];
        for (LLI i=0;i<n;i++) {
            cin >> x[i] >> y[i];
        }

        LLI oi = -1, maxim = INT_MIN;

        for (LLI i=0;i<n;i++) {
            LLI curr = 0;
            for (LLI j=0;j<n;j++) {
                LLI dis = abs(x[i] - x[j]) + abs(y[i] - y[j]);
                if (dis <= k) {
                    curr++;
                }
            }

            if (curr > maxim) {
                maxim = curr;
                oi = i;
            }
        }



        if (maxim != n) {
            cout << "-1\n";
        } else {
            cout << "1\n";
        }

    }

    return 0;
}