class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        int i=0, ans = 0;
        while(i < n) {
            
            if (arr[i] <= i) {
                ans = arr[i];
                break;
            }
            
            if (arr[i] != i+1) {
                int temp = arr[arr[i]-1];
                if (temp == arr[i]) {
                    ans = temp;
                    break;
                }
                arr[arr[i]-1] = arr[i];
                arr[i] = temp;
            } else {
                i++;
            }
        }
        
        return ans;
    }
};