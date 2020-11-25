#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    LLI x, y, l, r;
    cin >> x >> y;
    cin >> l >> r;

    LLI mask = (1 << (r-l+1)) - 1;

    mask = ((mask) << (l - 1)) & y;

    x = x | mask;
    cout << x << "\n";

    return 0;
}