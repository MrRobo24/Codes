#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI optimalBSTCost(LLI* arr, LLI* freq, LLI* pSum, LLI n) {

    LLI dp[n+1][n+1];
    for (LLI g=0;g<n;g++) {
        for (LLI i=0,j=g;j<n;i++,j++) {
            if (g == 0) {
                dp[i][j] = freq[i];
            } else if (g == 1) {
                dp[i][j] = min( freq[i] + 2 * freq[j], 2 *freq[i] + freq[j]);
            } else {
                LLI minim = INT_MAX;
                for (LLI k=i;k<=j;k++) {
                    minim = min(minim, (k==0? 0 : dp[i][k-1])+
                                        (k==n-1? 0 : dp[k+1][j]) +
                                        pSum[j+1] - pSum[i]);
                }

                dp[i][j] = minim;
            }
        }
    }

    return dp[0][n-1];
}



int main() {

    LLI n;
    cin >> n;
    LLI arr[n], freq[n], pSum[n+1];
    pSum[0] = 0;
    for (LLI i=0;i<n;i++) {
        cin >> arr[i];
    }
    for (LLI i=0;i<n;i++) {
        cin >> freq[i];
        pSum[i+1] =  freq[i] + pSum[i];
    }

    cout << optimalBSTCost(arr, freq, pSum, n) << "\n";
    return 0;
}