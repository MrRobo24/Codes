#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        if (n == 1) {
            cout << 0 << "\n";
        } else if (n == 2) {
            cout << 1 << "\n";
        } else if (n == 3) {
            cout << 2 << "\n";
        }   else {
            cout << ((n%2 == 0)? 2 : 3 )<< "\n"; 
        }
        
    }

    return 0;
}
