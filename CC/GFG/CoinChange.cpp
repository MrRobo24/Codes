// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define LLI long long
class Solution {
  public:
  
    LLI dp[1001][1001];
    
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    
    
    LLI count( int s[], int m, int n ) {
        if (m <= 0 || n <0) {
            return 0;
        }
        
        if (n == 0) {
            return 1;
        }
        
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        
        
        if (s[m-1] <= n) {
            dp[m][n] = count(s, m, n-s[m-1]) + count(s, m-1, n);
        } else {
            dp[m][n] = count(s, m-1, n);
        }
        
        return dp[m][n];
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends