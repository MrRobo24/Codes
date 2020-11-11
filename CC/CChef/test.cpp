//WA & TLE
/*
There are errors in normal case without 1 and with 1 cases too.
*/
#include <bits/stdc++.h>
#define LLI long long
#define MOD 1000000007
using namespace std;

LLI calcOld(LLI onei, LLI r, LLI n, LLI* arr, LLI* pfx, LLI* odx) {
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

        for (LLI i=0;i<cycle;i++) {
            sum = (sum%MOD + pfx[n]%MOD - odx[n]%MOD)%MOD;
            if (preodd) {
                sum = (sum%MOD + 1)%MOD;
            } else {
                sum = (sum%MOD - 1)%MOD;
            }

            if (endodd) {
                sum = (sum%MOD + 1)%MOD;
            } else {
                sum = (sum%MOD - 1)%MOD;
            }
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

        for (LLI i=0;i<cycle;i++) {
            sum = (sum%MOD + pfx[n]%MOD - odx[n]%MOD)%MOD;

            if (endodd) {
                sum = (sum%MOD + 1)%MOD;
            } else {
                sum = (sum%MOD - 1)%MOD;
            }
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

    //cout << sum << "\n";
    return sum;
    //Inserting current answer in BST
    // if (!root) {
    //     root = insertNode(root, {r, sum});
    // } else {
    //     insertNode(root, {r, sum});
    // }
}

LLI calcRemSum( LLI* pfx,
                LLI* odx, 
                LLI* arr,
                LLI cycle, 
                LLI rem, 
                LLI onei,
                LLI n) {
    
    bool preodd = false, endodd = false;
    preodd = arr[onei-1] % 2 != 0;
    endodd = arr[n-1] % 2 != 0;
    LLI sum = 0;
    if (onei == 0) {
        if ((rem > 1) ||
                    (rem == 1 && cycle == 0)) {
                    sum = (sum%MOD + 1)%MOD;
        }
    } else if (onei > 0 && onei < n-1) {
        bool preodd = false, endodd = false;
        preodd = arr[onei-1] % 2 != 0;
        endodd = arr[n-1] % 2 != 0;

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

        if (rem == 0 && !endodd) {
            sum = (sum%MOD + 1)%MOD;
        } else if (rem != 0) {

            sum = (sum%MOD + pfx[rem]%MOD  - odx[rem]%MOD) %MOD;
            if (arr[rem-1]%2 != 0) {
                sum = (sum%MOD + 1)%MOD;
            }
        }

    }

    return sum;
 

}



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
            if (arr[i] == 1) {
                onei = i;
            }
            if (arr[i] %2 == 0) {
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

        //cin >> q;
        q = 100;
        while (q > 0) {
            LLI r = q;//(rand() % (50 - 1 + 1)) + 1;
            q--;
            //cin >> r;
            cout << "R = " << r << "\n";
            LLI cycle = 0, rem = 0, sum = 0;

            cycle = r / n;
            rem = r % n;
            //calling the old function for verification
            LLI old = calcOld(onei, r, n, arr, pfx, odx);

            //working with map
            if (onei != 0 && !history.empty()) {
                for (map<LLI,LLI>::iterator it = history.begin();it != history.end();it++) {
                    cout << it->first << "->" << it->second << ", ";
                }
                cout << "\n";

                map<LLI,LLI>::iterator last = history.find(r);
                if (last != history.end()) {
                    cout << "FOUND\n";
                    cout << last->second << "\n";
                    continue;
                } else {
                    LLI curr = r;

                    if (history.rbegin()->first > r 
                        && history.begin()->first < r) {
                        while (curr > 0 && history[curr] == 0) {
                            curr--;
                        }
                    } else if (history.rbegin()->first < r) {
                        curr = history.rbegin()->first;
                    } else {
                        curr = 0;
                    }

                    if (curr != 0) {
                        //found the suitable just smaller value
                        cout << "FOUND AT " << curr << " \n";
                        LLI lSum = history[curr];
                        LLI lCycle = curr / n;
                        LLI lRem = curr % n;

                        cycle = cycle - lCycle;
                        cout << "NEW CYCLE " << cycle << "\n";
                        LLI remSumOld = calcRemSum(pfx, odx, arr, lCycle, lRem, onei, n);
                        
                        cout << "REMSUM OLD " << remSumOld << "\n";
                        lSum  = (lSum%MOD - remSumOld%MOD)%MOD;
                        
                        sum = lSum;
                        cout << "NEW SUM INIT " << sum << "\n";
                    }
                }

            }
            //ending map



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

                for (LLI i=0;i<cycle;i++) {
                    sum = (sum%MOD + pfx[n]%MOD - oc%MOD)%MOD;
                    if (preodd) {
                        sum = (sum%MOD + 1)%MOD;
                    } else {
                        sum = (sum%MOD - 1)%MOD;
                    }

                    if (endodd) {
                        sum = (sum%MOD + 1)%MOD;
                    } else {
                        sum = (sum%MOD - 1)%MOD;
                    }
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

                for (LLI i=0;i<cycle;i++) {
                    sum = (sum%MOD + pfx[n]%MOD - oc%MOD)%MOD;

                    if (endodd) {
                        sum = (sum%MOD + 1)%MOD;
                    } else {
                        sum = (sum%MOD - 1)%MOD;
                    }
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
            //matching the old and new answers
            cout << "OLD SUM = " << old << " NEW SUM = " << sum << "\n";
            if (old != sum) {
                cout << "MISMATCH\n";
                cout << "MISMATCH\n";
                cout << "MISMATCH\n";
                cout << "MISMATCH\n";
                break;
            } else {
                cout << "MATCH\n";
            }
            
            history[r] = sum;

        }

    }
}
