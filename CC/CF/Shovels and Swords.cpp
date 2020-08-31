#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;

    while (t--) {
        LLI a,b;
        cin >> a >> b;
        cout << min(a,min(b, (LLI)(a+b)/3)) << "\n";
    }

    return 0;

}
