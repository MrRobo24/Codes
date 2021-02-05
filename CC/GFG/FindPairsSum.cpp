// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        
        unordered_map<int, int> count;
        for (int i=0;i<n;i++) {
            count[arr[i]]++;
        }
        
        
        int pairs = 0;
        for (int i=0;i<n;i++) {
            pairs += count[k - arr[i]];
            
            if (arr[i]*2 == k) {
                pairs--;
            }
        }
        
        return pairs/2;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends