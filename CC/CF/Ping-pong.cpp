#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI x,y;
        cin >> x >> y;
        if (x == 0) {
            cout << x << y << "\n";
            continue;
        }
        if (y == 0) {
            cout << x << y << "\n";
            continue;
        }
        
        cout << x-1 << " " << y << "\n";
    }


    return 0;
}