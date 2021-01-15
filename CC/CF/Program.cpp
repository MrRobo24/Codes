//WA Got the question wrong
#include <bits/stdc++.h>

#define LLI long long
using namespace std;

void solve(LLI n, LLI m) {   
    string p;
    cin >> p;
    LLI add[n+1];
    add[0] = 0;
    cout << p << " CHECK\n";
    LLI i=1;
    for (auto c: p) {
        if (c == '+') {
            add[i] = add[i-1] + 1;
        } else {
            add[i] = add[i-1];
        }
        i++;
    }
    cout << "ADD: ";
    for (auto e: add) {
        cout << e << " ";
    }
    cout << "\n";
    LLI total = add[n] - (n-add[n]);
    cout << total << "TOT\n";

    while (m--) {
        LLI l, r;
        cin >> l >> r;
        l--;
        r--;
        LLI change = add[r+1]-add[l+1] - ((r-l+1) - add[r+1]-add[l+1]);
        cout << change << "CHANGE\n";
        cout << total - change << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n, m;
        cin >> n >> m;
        solve(n, m);
    }

    return 0;
}