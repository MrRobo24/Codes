#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    LLI t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        LLI n = s.size();
        LLI curr = 0;
        vector <LLI> scores;
        bool flag = false;

        for (LLI i=0;i<n;i++) {
            char ch = s[i];
            if (ch == '1') {
                flag = false;
                curr++;
            } else if (!flag) {
                flag = true;
                scores.push_back(curr);
                curr = 0;
            }
        }

        if (!flag) {
            scores.push_back(curr);
        }

        sort(scores.begin(), scores.end());

        LLI ans = 0;
        for (LLI i=scores.size()-1;i>=0;i = i - 2) {
            ans += scores[i];
        }

        cout << ans << "\n";




        //for (LLI i=0;i<scores.size();i++) {
          //  cout << scores[i] << " ";
        //}
        //cout << '\n';
    }



    return 0;
}
