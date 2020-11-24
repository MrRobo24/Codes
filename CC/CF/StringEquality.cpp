//AC Later
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
        string a, b;
        cin >> a;
        cin >> b;

        LLI af[26] = {0};
        LLI bf[26] = {0};

        for (LLI i=0;i<n;i++) {
            af[a[i]-'a']++;
            bf[b[i]-'a']++;
        }

        bool flag = false;

        for (LLI i=0;i<25;i++) {
            if (af[i] < bf[i]) {
                flag = true;
                break;
            } else if ((af[i] -= bf[i]) % k) {
                //will enter when term is not multiple of k
                flag = true;
                break;
            }

            af[i+1] += af[i];
        }

        if (flag) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }

    return 0;
}