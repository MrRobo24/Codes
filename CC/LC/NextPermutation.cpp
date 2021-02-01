#include <bits/stdc++.h>
#define LLI int
class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        LLI n = arr.size();
        if (n == 1) {
            return;
        }
        LLI def = n-1;
        while (def > 0 && arr[def] <= arr[def-1]) {
            def--;
        }
        
        def--;
        
        if (def == -1) {
            sort(arr.begin(), arr.end());
        } else {
            
            LLI greater = n-1;
            while (greater > def && arr[greater] <= arr[def]) {
                    greater--;
            }
            //cout << greater << "\n";
            swap(arr[greater], arr[def]);
            reverse(arr.begin()+def+1, arr.end());
        }
    }
};