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
        LLI e = 0, ec = 0, o = 0, oc = 0;
        priority_queue<LLI> eq, oq;
        for (LLI i=0;i<n;i++) {
            if (arr[i] % 2 == 0) {
                e += arr[i];
                eq.push(arr[i]);
                ec++;
            } else {
                o += arr[i];
                oq.push(arr[i]);
                oc++;
            }
        }

        if (ec == 0) {
            cout << "Bob\n";
            continue;
        } 

        if (oc == 0) {
            cout << "Alice\n";
            continue;
        }

        if (e > o) {
            cout << "Alice\n";
        } else if (e < o) {

            while (ec > 0 && oc > 0 && e < o) {
                o -= oq.top();
                e -= eq.top();
                oq.pop();
                eq.pop();
                ec--;
                oc--;
            }

            if (ec == 0 && oc > 1) {
                cout << "Bob\n";
            } else if (ec > 0 && oc == 0) {
                cout << "Alice\n";
            } else {
                cout << "Tie\n";
            }

        } else {
            cout << "Alice\n";
        }

    }

    return 0;
}