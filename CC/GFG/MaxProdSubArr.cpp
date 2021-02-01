// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    if (n == 1) {
	        return arr[0];
	    }
	    
	    long long minim = arr[0], maxim = arr[0], ans = arr[0];
	    for (int i=1;i<n;i++) {
	        if (arr[i] < 0) {
	            long long t = minim;
	            minim = maxim;
	            maxim = t;
	        }
	        
	        minim = min((long long)arr[i], arr[i]*minim);
	        maxim = max((long long)arr[i], arr[i]*maxim);
	        
	        ans = max(ans, maxim);
	    }
	    
	    
	    
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends