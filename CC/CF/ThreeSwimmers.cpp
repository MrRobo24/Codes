#include <bits/stdc++.h>
#define LLI unsigned long long
#define umap unordered_map
#define uset unordered_set
#define all(v) v.begin(),v.end()

using namespace std;

LLI solve(LLI n, LLI p) {
    return ceil((long double)p/n)*n - p;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI p, a, b, c;
        cin >> p >> a >> b >> c;
        LLI aa = solve(a, p);
        LLI bb = solve(b, p);
        LLI cc = solve(c, p);

        cout << min(min(aa, bb), cc) << "\n";
    }

    return 0;

}