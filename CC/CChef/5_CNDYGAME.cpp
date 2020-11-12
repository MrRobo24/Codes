//AC & TLE
/*
There are errors in normal case without 1 and with 1 cases too.
*/
#include <bits/stdc++.h>
#define LLI long long
#define MOD 1000000007
using namespace std;

int main() {

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    LLI t;
    cin >> t;
    while (t--) {

        map<LLI,LLI> history;
        LLI n,q,onei = -1, oc = 0, ec = 0;
        cin >> n;
        LLI arr[n];
        LLI pfx[n+1], odx[n+1];
        pfx[0] = 0;
        odx[0] = 0;
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
        }

        for (LLI i=0;i<n;i++) {
            
            if (arr[i] == 1) {
                onei = i;
            }
            if ( (arr[i]) %2 == 0) {
                ec++;
                odx[i+1] = odx[i];
            } else {
                oc++;
                odx[i+1] = (odx[i]%MOD + 1)%MOD;
            }

            pfx[i+1] = (pfx[i]%MOD + arr[i]%MOD)%MOD;
        }

        // cout << "PFX: ";
        // for (LLI i=0;i<n+1;i++) {
        //     cout << pfx[i] << " ";            
        // }
        // cout << "\n";

        cin >> q;
        //q = 1;
        while (q--) {
            LLI r;
            cin >> r;
            LLI cycle = 0, rem = 0, sum = 0;

            cycle = r / n;
            rem = r % n;

            if (onei == 0) {
                sum = (sum%MOD + cycle%MOD)%MOD;
                if ((rem > 1) ||
                    (rem == 1 && cycle == 0)) {
                    sum = (sum%MOD + 1)%MOD;
                }
            } else if (onei > 0 && onei < n-1) {
                bool preodd = false, endodd = false;
                preodd = arr[onei-1] % 2 != 0;
                endodd = arr[n-1] % 2 != 0;

                sum = (sum%MOD + ((pfx[n]%MOD - oc%MOD)%MOD * cycle%MOD)%MOD)%MOD;
                if (preodd) {
                    sum = (sum%MOD + cycle%MOD)%MOD;
                } else {
                    sum = (sum%MOD - cycle%MOD)%MOD;
                }

                if (endodd) {
                    sum = (sum%MOD + cycle%MOD)%MOD;
                } else {
                    sum = (sum%MOD - cycle%MOD)%MOD;
                }

                if (rem == 0 && !endodd) {
                    sum = (sum%MOD + 1)%MOD;
                } else if (rem != 0) {

                    sum = (sum%MOD + pfx[rem]%MOD  - odx[rem]%MOD) %MOD;
                    if (rem-1 < onei) {
                        if (arr[rem-1]%2 != 0) {
                            sum = (sum%MOD + 1)%MOD;
                        }
                    } else if (rem-1 == onei) {
                        sum = (sum%MOD + 1)%MOD;
                    } else {
                        if (preodd) {
                            sum = (sum%MOD + 1)%MOD;
                        } else {
                            sum = (sum%MOD - 1)%MOD;
                        }
                        if (arr[rem-1]%2 != 0) {
                            sum = (sum%MOD + 1)%MOD;
                        }
                    }

                }

            } else {
                bool endodd = false;
                endodd = arr[n-1] % 2 != 0;

                sum = (sum%MOD + ((pfx[n]%MOD - oc%MOD)%MOD * cycle%MOD)%MOD)%MOD;
                if (endodd) {
                    sum = (sum%MOD + cycle%MOD)%MOD;
                } else {
                    sum = (sum%MOD - cycle%MOD)%MOD;
                }

                if (rem == 0 && !endodd) {
                    sum = (sum%MOD + 1)%MOD;
                } else if (rem != 0) {

                    sum = (sum%MOD + pfx[rem]%MOD  - odx[rem]%MOD) %MOD;
                    if (arr[rem-1]%2 != 0) {
                        sum = (sum%MOD + 1)%MOD;
                    }
                }

            }

            cout << sum << "\n";
        }

    }
}