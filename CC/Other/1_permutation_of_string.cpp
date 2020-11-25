#include <bits/stdc++.h>
#define LLI long long
using namespace std;

void func(string ans, vector<char> s) {
    if (ans.size() == s.size()) {
        cout << ans << "\n";
        return;
    }

    for (LLI i=0;i<s.size();i++) {
        char ch = s[i];
        if (ch != ' ') {
            s[i] = ' ';
            func(ans + ch, s);
            s[i] = ch;
        }
    }
}

int main() {
    string inpS;
    cout << "Enter the string: ";
    cin >> inpS;

    vector<char> s;
    for (LLI i=0;i<inpS.size();i++) {
        s.push_back(inpS[i]);
    }

    func("", s);


    return 0;
}


