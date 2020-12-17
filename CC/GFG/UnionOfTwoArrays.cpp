#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {
    
    LLI t;
    cin >> t;
    while (t--) {
        LLI n, m;
        cin >> n >> m;
        LLI crr[100001], c = 0;
        memset(crr, 0, sizeof(crr));
        LLI arr[n], brr[m];
        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
            if (!crr[arr[i]]) {
                crr[arr[i]] = 1;
                c++;
            }
        }
        for (LLI i=0;i<m;i++) {
            cin >> brr[i];
            if (!crr[brr[i]]) {
                crr[brr[i]] = 1;
                c++;
            }
        }
        
        cout << c << '\n';
        
    }
    
    
    
    return 0;
}