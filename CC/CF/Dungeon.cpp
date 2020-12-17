//WA
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI a, b, c;
        cin >> a >> b >> c;
        LLI sum = a-1 + b-1 + c-1;
        sum = sum - 2*((LLI)sum/7);
        if ( sum != 0 && sum % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }


    return 0;
}