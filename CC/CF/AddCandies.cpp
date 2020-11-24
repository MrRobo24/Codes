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
        LLI n;
        cin >> n;
        cout << n << "\n";
        for (LLI i=0;i<n;i++) {
            cout << i+1 << " ";
        }
        cout << "\n";
    }

    return 0;
}