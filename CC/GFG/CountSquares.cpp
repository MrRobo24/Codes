// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution {
  public:
    int countSquares(int N) {

        //used newton's method, could have used sqrt function
        //binary search is giving overflow error.
        long i = N;
        while (i*i > N) {
            i = (i + N/i)/2;
        }
        
        if (i*i == N) {
            return i-1;
        } else {
            return i;
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends