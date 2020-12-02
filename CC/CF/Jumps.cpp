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
        LLI x;
        cin >> x;
        LLI root = (LLI)(sqrt(1 + 8*x) - 1)/2;
        LLI val = (LLI)(root*(root+1))/2;
        if (val == x) {
            cout << root << "\n";
        } else {
            root++;
            val = (LLI)(root*(root+1))/2;
            if (val - x == 1) {
                cout << root + 1 << "\n";
            } else {
                cout << root << "\n";
            }

        }
    }


    return 0;
}