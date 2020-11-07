#include <bits/stdc++.h>
#define LLI long long
#define MOD 1000000007
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI t;
    cin >> t;
    while (t--) {
        LLI n,q, extra = 0, pos = -1;
        cin >> n;
        LLI arr[n];
        LLI pref[n+1];
        pref[0] = 0;
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
            LLI val = arr[i];

            if (arr[i]%2 != 0 && i != n-1) {
                val--;

                if (arr[i] == 1) {
                    extra = 1;
                    pos = i;
                }
                    
            } else if (arr[i]%2 == 0 && i == n-1) {
                val--;
            }

            pref[i+1] = (pref[i]%MOD + val%MOD)%MOD;
        } 

        // cout << "PFX: ";
        // for (LLI i=0;i<n+1;i++) {
        //     cout << pref[i] << " ";
        // }
        // cout << "\n";
        cin >> q;
        while (q--) {
            LLI r;
            cin >> r;

            LLI cycle = r / n;
            LLI rem = r % n;
            //cout << cycle << " " << rem << "\n";
            LLI sum = 0;
            for (LLI i=0;i<cycle;i++) {
                sum = (sum%MOD + pref[n]%MOD - extra)%MOD;
            }

            sum = (sum%MOD + pref[rem]%MOD)%MOD;

            if (extra) {
                if (rem-1 > pos) {
                    sum = sum - extra;
                }
            }

            if (rem > 0 && arr[rem-1]%2 != 0) {
                sum = (sum%MOD + 1)%MOD;
            } else if (rem == 0 && arr[n-1]%2 == 0) {
                sum = (sum%MOD + 1)%MOD;
            }

            cout << sum << "\n";

        }

    }
}
