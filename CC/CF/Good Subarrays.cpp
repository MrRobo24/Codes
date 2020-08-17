//TLE
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {


    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        string s;
        cin >> s;
        vector<LLI> arr;
        for (LLI i=0;i<n;i++) {
            arr.push_back(s[i] - '0');
        }

        LLI counter = 0;

        vector<LLI> pfx;
        LLI sum = 0;
        for (LLI i=0;i<n;i++) {
            sum += arr[i];
            pfx.push_back(sum);
        }

        for (LLI i=0;i)

    }

    return 0;
}
