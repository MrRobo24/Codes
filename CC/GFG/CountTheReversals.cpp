#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI count(string s) {

    stack<char> st;
    LLI n = s.size();
    if (n%2 != 0) {
        return -1;
    }

    for (LLI i=0;i<n;i++) {
        char ch = s[i];
        if (ch == '{') {
            st.push(ch);
        } else {
            if (!st.empty() && st.top() == '{') {
                st.pop();
            } else {
                st.push(ch);
            }
        }
    }

    if (!st.empty()) {
        
        LLI a = 0, b = 0;
        while (!st.empty()) {
            
            char ch = st.top();
            if (ch == '{') {
                a++;
            } else {
                b++;
            }
            st.pop();
        }
        return (a+1)/2 + (b+1)/2;
    }

    return 0;
}


int main() {

    LLI t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << count(s) << "\n";
    }
    return 0;
}