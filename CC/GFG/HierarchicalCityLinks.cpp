#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI a,b;
LLI solve(LLI x, LLI y) {
    if (x == y) {
        return 0;
    }

    if (x == 1) {
        return 1 + solve(x, y/2);
    }
    if (y == 1) {
        return 1 + solve(x/2, y);
    }

    if (x == b) {
        return 0;
    }

    if (y == a) {
        return 0;
    }

    return 2 + solve(x/2, y/2);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI t;
    cin >> t;
    while (t--) {
        LLI x, y;
        cin >> x >> y;
        a = x;
        b = y;
        cout << solve(x, y) << "\n";   
    }
    return 0;
}