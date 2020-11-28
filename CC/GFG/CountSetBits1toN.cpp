#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI solve(LLI n) {
    if (n == 0) {
        return 0;
    }
    LLI x = log2(n);
    return pow(2,x-1)*x + (n - pow(2,x) + 1) + solve(n - pow(2,x));
}

int main() {
    LLI n;
    cin >> n;
    cout << solve(n) << "\n";
}