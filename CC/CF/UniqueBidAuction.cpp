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
        LLI arr[n];
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
        }

        map<LLI, vector<LLI> > freq;
        for (LLI i=0;i<n;i++) {
            freq[arr[i]].push_back(i);
        }

        map<LLI, vector<LLI> >:: iterator itr = freq.begin();
        LLI flag = 0;
        while (itr != freq.end()) {
            if (itr->second.size() == 1) {
                cout << itr->second[0] + 1 << "\n";
                flag = 1;
                break;
            }
            itr++;
        }

        if (!flag) {
            cout << "-1" << "\n";
        }
    }

    return 0;
}