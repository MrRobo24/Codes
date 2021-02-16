//AC
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        string arr[n];
        vector< set<string> >pre(26);

        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
            pre[arr[i][0]-'a'].insert(arr[i].substr(1));
        }

        LLI total = 0;

        for (LLI i=0;i<26;i++) {

            if (!pre[i].empty()) {
                for (LLI j=i+1;j<26;j++) {
                    if (!pre[j].empty()) {
                        vector<string> inter;
                        set_intersection(pretosuf[i].begin(), pretosuf[i].end(),
                                        pretosuf[j].begin(), pretosuf[j].end(), back_inserter(inter));
                        
                        LLI a = pretosuf[i].size() - in.size();
                        LLI b = pretosuf[j].size() - in.size();
                        total += 2 * (a * b);
                        
                    }

                }
            }

        }

        cout << total << "\n";
    }

    return 0;
}
