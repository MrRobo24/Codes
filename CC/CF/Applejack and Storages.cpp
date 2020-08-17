//AC
#include <bits/stdc++.h>
#define LLI long long int

using namespace std;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    unordered_map<LLI,LLI> fMap;
    vector <LLI> groups(100001, 0);
    LLI n;
    cin >> n;
    for (LLI i=0;i<n;i++) {
        LLI plankLength;
        cin >> plankLength;
        fMap[plankLength]++;
        groups[fMap[plankLength]]++;
    }

    LLI q;
    cin >> q;
    while (q--) {
        LLI plankLength;
        char ch;
        cin >> ch >> plankLength;
        LLI extra = 0;
        if (ch == '+') {
            fMap[plankLength]++;
            groups[fMap[plankLength]]++;
        } else {
            groups[fMap[plankLength]]--;
            fMap[plankLength]--;
        }

        if (groups[8] >= 1) {
            cout << "YES\n";
        } else if (groups[6] >= 2) {
            cout << "YES\n";
        } else if (groups[6] == 1 && groups[2] >= 2) {
            cout << "YES\n";
        } else if (groups[4] >= 2) {
            cout << "YES\n";
        } else if (groups[4] == 1 && groups[2] >= 3) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }


    return 0;
}
