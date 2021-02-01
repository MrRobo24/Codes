class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if (n == 0 || n == 1) {
            return 0;
        }
        
        int ans = 0;
        int buy = 0, sell = 1;
        while (sell < n) {
            if (prices[buy] < prices[sell]) {
                ans = max(ans, prices[sell] - prices[buy]);
            } else {
                buy = sell;
            }
            
            sell++;
        }
        
        return ans;
    }
};