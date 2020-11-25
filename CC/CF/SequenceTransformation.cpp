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

        map<LLI, LLI> freq;
        for (LLI i=0;i<n;i++) {
            if (i>0 && arr[i] == arr[i-1]) {
                continue;
            } else {
                freq[arr[i]]++;
            }
        }

        // map<LLI, vector<LLI> >:: iterator itr = freq.begin();
        // while (itr != freq.end()) {
        //     cout << itr->first << " -> ";
        //     for (LLI i=0;i<itr->second.size();i++) {
        //         cout << itr->second[i] << " ";
        //     }
        //     cout << "\n";
        //     itr++;
        // }

        map<LLI, LLI>:: iterator itr = freq.begin();
        LLI minim = INT_MAX;
        while (itr != freq.end()) {
            LLI curr = itr->second + 1;
            if (itr->first == arr[0]) {
                curr--;
            }
            if (itr->first == arr[n-1]) {
                curr--;
            }

            minim = min(curr, minim);
            itr++;
        }
        cout << minim << "\n";
    }

    return 0;
}