#include <bits/stdc++.h>
#define LLI long long

using namespace std;
class Solution {
public:
    LLI dp[1001];
    Solution() {
        memset(dp,-1, sizeof(dp));
    }
    int numTrees(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        if (dp[n] != -1) {
            return dp[n];
        }


        LLI sum = 0;
        for (LLI i=0;i<n;i++) {
            sum = sum + numTrees(i)*numTrees(n-1-i);
        }
        return dp[n] = sum;
    }
};

int main() {
    int n;
    cin >> n;
    Solution s;
    cout << s.numTrees(n) << "\n";
    return 0;
}