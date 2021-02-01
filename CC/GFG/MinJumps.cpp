// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return minimum number of jumps to end of array


int minJumps(int arr[], int n){

    if (arr[0] == 0) {
        return -1;
    }

    int maxReachable, jumps, steps;
    maxReachable = arr[0];
    jumps = 1;
    steps = arr[0];

    for (int i=1;i<n;i++) {
        if (i == n-1) {
            return jumps;
        }

        maxReachable = max(maxReachable, i + arr[i]);
        steps--;

        if (steps == 0) {
            if (i >= maxReachable) {
                return -1;
            }
            jumps++;
            steps = maxReachable - i;
            
        }
    }

    return -1;
    
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends