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
        string txt = "abc";
        for (LLI i=0;i<n;i++) {
            cout << txt[i%3];
        }
        cout << "\n";
    }

    return 0;
}