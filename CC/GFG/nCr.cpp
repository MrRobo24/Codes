// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++
#define LLI long long
#define MOD 1000000007
class Solution{
public:

    LLI dp[1001][1001];
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    
    int nCr(int n, int r){
        if (r < 0 || n <= 0 || r > n) {
            return 0;
        }
        
        if (r == 0 || n == r) {
            return 1;
        }
        
        if (dp[n][r] != -1) {
            return dp[n][r];
        }
        
        dp[n][r] = (nCr(n-1, r-1) + nCr(n-1, r))%MOD;
        return dp[n][r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends