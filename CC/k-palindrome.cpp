#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	LLI t;
	cin >> t;
	while(t--) {
		LLI k,n;
		string s;
		cin >> s;
		cin >> k;
		n = s.size();
		if ((k % 2 == 0 && n % 2 != 0) || (k % 2 != 0 && n % 2 == 0)) {
			cout << -1 << "\n";
		} else {

			k = k / 2;
			LLI curr = 0;
			priority_queue<LLI, vector<LLI>, greater<LLI> > diff;
			for (LLI i=0;i<n/2;i++) {
				diff.push(abs(s[i] - s[n - i - 1]));
				if (s[i] - s[n - i - 1] == 0) {
					curr++;
				}
			}

			if (curr == k) {
				cout << 0 << "\n";
			} else if (curr > k) {
				cout << curr - k << "\n";
			} else {
				LLI cost = 0;
				while (k--) {
					cost += diff.top();
					diff.pop();
				}
				cout << cost <<  "\n";
			}

		}

		/*
        while (!diff.empty()) {
            cout << diff.top() << " ";
            diff.pop();
        }
        cout << "\n";
*/
	}


	return 0;
}
