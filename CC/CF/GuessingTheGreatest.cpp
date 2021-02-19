//AC LATER
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI ask(LLI l, LLI r) {
    if (l >= r) {
        return -1;
    }

    cout << "? " << l+1 << " " << r+1 << "\n";
    cout.flush();
    LLI smax;
    cin >> smax;
    return smax-1;
    
}

void print(LLI r) {
    cout << "! " <<  r << "\n";
    cout.flush();
}

int main() {

    LLI n;
    cin >> n;
    LLI l = 0, r = n;
    
    while (l + 1 < r) {
        LLI mid = l + (r-l)/2;
        LLI smax = ask(l, r-1);

        if (smax < mid) {
            if (smax == ask(l, mid-1)) {
                r = mid;
            } else {
                l = mid;
            }
        } else { 
            if (smax == ask(mid, r-1)) {
                l = mid;
            } else {
                r = mid;
            }
        }
    }

    print(r);

    return 0;
}
