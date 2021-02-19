//WA
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI ask(LLI l, LLI r) {
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    LLI smax;
    cin >> smax;
    return smax;
    
}

void print(LLI r) {
    cout << "! " <<  r << "\n";
    cout.flush();
}

int main() {

    LLI n;
    cin >> n;
    LLI l = 1, r = n;
    LLI smax = ask(l, r);
    while (l < r) {
        LLI mid = l + (r-l)/2;
        LLI s2max = 0;
        if (l == r-1) {
            s2max = ask(l,r);
            if (s2max == l) {
                print(r);
            } else {
                print(l);
            }
            return 0;
        }

        if (smax < mid) {
            s2max = ask(l, mid-1);
            if (smax == s2max) {
                r = mid-1;
            } else {
                l = mid;
            }
        } else {
            s2max = ask(mid, r);
            if (smax == s2max) {
                l = mid;
            } else {
                r = mid-1;
            }
        }

        smax = s2max;
    }

    return 0;
}
