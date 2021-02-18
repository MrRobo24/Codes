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
       k--;
       if (n % 2 == 0) {
           cout << (k%n) + 1 << "\n";
       } else {
           LLI frq = (n-1)/2;
           LLI skips = k / frq;

           cout << ((k + skips)%n) + 1 << "\n";
       }
    }

    return 0;
}
