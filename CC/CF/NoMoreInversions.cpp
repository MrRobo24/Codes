#include <bits/stdc++.h>

#define LLI long long
using namespace std;

void solve(LLI n, LLI k) {   
    LLI arr[n];
    LLI i=0, c=1;
    while (i<n) {   
        arr[i] = c;
        if (i < k-1) {
            c++;
        } else {
            c--;
        }
        i++;
    }

    i = n-1;
    c = k;
    LLI p[k];
    memset(p, -1, sizeof(p));
    while (k) {
        if (p[arr[i]-1] == -1) {
            p[arr[i]-1] = k--;
        }
        i--;
        
    }

    for (auto i: p) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n, k;
        cin >> n >> k;
        solve(n, k);
    }

    return 0;
}