//AC Later
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI counting(LLI p[], LLI n) {
    sort(p, p+n);
    LLI num = p[(n+2)/2 - 1] -  p[(n+1)/2 - 1] + 1;
    return num;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        LLI x[n], y[n];
        for (LLI i=0;i<n;i++) {
            cin >> x[i] >> y[i];
        }

        cout << counting(x, n) * counting(y, n) << "\n";
    }

    return 0;
}
