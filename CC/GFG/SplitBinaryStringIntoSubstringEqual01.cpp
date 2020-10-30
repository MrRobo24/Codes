#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {
    string s;
    cin >> s;
    LLI a = 0, b = 0, p = 0;
    for (LLI i=0;i<s.size();i++) {
        if (s[i] == '0') {
            a++;
        } else {
            b++;
        }

        if (a == b) {
            p++;
            a = 0;
            b = 0;
        }
    }

    cout << p << "\n";
}