#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI counter = 0;
void func(string ans, vector<char> s, LLI l) {
    if (l == s.size()) {
        counter++; // just for testing
        if (ans != "")
            cout << ans << "\n";
        return;
    }
    l++;
    func(ans + s[l-1], s, l);
    func(ans, s, l);
}


int main() {
    string inpS;
    cout << "Enter the string: ";
    cin >> inpS;

    vector<char> s;
    for (LLI i=0;i<inpS.size();i++) {
        s.push_back(inpS[i]);
    }

    func("", s, 0);
    cout << "COUNT: " << counter << "\n";
    return 0;
}
