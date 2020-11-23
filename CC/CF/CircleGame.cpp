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
        LLI d, k;
        cin >> d >> k;
        LLI z = floor(d / (sqrt(2)*k));
        LLI left = d*d - 2*k*k*z*z;

        if ((k*k*(2*z + 1)) > left) {
            cout << "Utkarsh\n";
        } else {
            cout << "Ashish\n";
        }

    }

    return 0;
}