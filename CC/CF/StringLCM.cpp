#include <bits/stdc++.h>

#define LLI long long
using namespace std;

LLI gcd(LLI a, LLI b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a%b);
}

LLI lcm(LLI a, LLI b) {
    if (a < b) {
        swap(a, b);
    }

    return (a/gcd(a, b))*b;
}

string solve(string a, string b) {   
    LLI len = lcm(a.size(), b.size());
    string achange = "", bchange = "";
    for (LLI i=0;i<len/a.size();i++) {
        achange += a;
    }
    for (LLI i=0;i<len/b.size();i++) {
        bchange += b;
    }

    if (achange == bchange) {
        return achange;
    } else {
        return "-1";
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }

    return 0;
}