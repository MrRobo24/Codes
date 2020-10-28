#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI dp[1001][1001];

LLI mcm(LLI* arr, LLI i, LLI j) {
    if (i >= j) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    LLI minim = INT_MAX;
    for (LLI k=i;k<=j-1;k++) {
        LLI curr = mcm(arr, i, k) 
        + mcm(arr, k+1, j) 
        + (arr[i-1] * arr[k] * arr[j]);

        minim = min(curr, minim);
    }

    dp[i][j] = minim;
    return dp[i][j];
}


int main() {

    LLI n;
    cout << "Enter size of arr: ";
    cin >> n;
    memset(dp, -1, sizeof(dp));
    LLI arr[n];
    for (LLI i=0;i<n;i++) {
        cin >> arr[i];
    }

    cout << "MINIMUM COST: " << mcm(arr, 1, n-1) << "\n";

    return 0;
}