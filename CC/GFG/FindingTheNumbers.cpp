// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int xor2 = 0, mask = 1;
        vector<int> ans(2,0);
        
        for (int i=0;i<n;i++) {
            xor2 ^= nums[i];
        }
        
        int xorC = xor2;
        while (xorC != 0) {
            if (xorC & 1) {
                break;
            }
            xorC = xorC >> 1;
            mask = mask << 1;
        }
        
        
        for (int i=0;i<n;i++) {
            ans[0] ^= ((nums[i] & mask)?  nums[i]: 0);
        }
        
        ans[1] = xor2 ^ ans[0];
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends