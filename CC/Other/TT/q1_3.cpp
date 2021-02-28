#include <bits/stdc++.h>
#define LLI long long 

using namespace std;

int main() {

    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;

        LLI arr[n], brr[n];
        LLI af[n+1];
        LLI bf[n+1];

        af[0] = 0;
        bf[0] = 0;

        for (LLI i=0;i<n;i++) {
            cin >> arr[i];
            af[i+1] = af[i] + arr[i];
        }
        for (LLI i=0;i<n;i++) {
            cin >> brr[i];
            bf[i+1] = bf[i] + brr[i];
        }


        LLI md = INT_MIN, mi = -1, mj = -1;
        for (LLI i=0;i<n;i++) { 
            for (LLI j=n-1;j>=i;j--) {
                LLI sa = 0, ba = 0;
                sa = af[j+1] - af[i];
                ba = bf[j+1] - bf[i];
                if (sa == ba) {
                    if (md < j-i) {
                        md = max(md, j-i);
                        mi = i;
                        mj = j;
                    }
                }
            }
        }

        if (mi == -1 || mj == -1) {
            cout << "No answer\n";
        } else {
            cout << mi << " " << mj << "\n";
        }
        
    }
    return 0;
}