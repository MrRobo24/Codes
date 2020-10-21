#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    string s;
    cin >> s;
    LLI n = s.size();

    for (LLI i=0;i<n/2;i++) {
        swap(s[i], s[n-1-i]);
    }

    cout << s << "\n";
    
    return 0;
}