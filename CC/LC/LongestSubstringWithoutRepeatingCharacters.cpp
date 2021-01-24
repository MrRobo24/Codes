//https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = s.size();
        unordered_set<char> st;
        int l = 0, r = 0, maxim = 0;
        
        while (r < n) {
            while (st.find(s[r]) != st.end()) {
                st.erase(s[l++]);
            }
            st.insert(s[r]);
            maxim = max(r-l+1, maxim);
            r++;
        }
        
        return maxim;
    }
};