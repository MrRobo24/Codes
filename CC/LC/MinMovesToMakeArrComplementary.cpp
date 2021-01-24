https://leetcode.com/problems/minimum-moves-to-make-array-complementary/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int lim) {
        int n = nums.size();
        int change[200001] = {0};
        int exact[200001] = {0};
        int maxSum = INT_MIN;
        for (int i=0;i<n/2;i++) {
            int a = nums[i];
            int b = nums[n-1-i];
            int sum = a + b;
            int low = min(a, b) + 1;
            int high = max(a,b) + lim;
            
            change[low]-=1;
            change[high+1]+=1;
            exact[a+b]+=1;
            
            maxSum = max(maxSum, a + b);
        }
        
        //cout << "MAX SUM " << maxSum << "\n";
        int steps = n, minSteps = INT_MAX;
        for (int i=2;i<=maxSum;i++) {
            steps += change[i];
            minSteps = min(steps - exact[i], minSteps);
            //cout << minSteps << "\n";
        }
        
        return minSteps;
        
    }
};