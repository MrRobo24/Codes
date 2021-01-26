//AC
#include <bits/stdc++.h>
#define LLI int64_t
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        if (ceil(log2(n)) == floor(log2(n))) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}