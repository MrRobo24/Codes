class Solution {
public:
    
    vector<string> dict;
    string s;
    bool dp[301];
    
    void breakit(int i) {
        
        if (i == s.size()) {
            dp[i] = true;
            return;
        }
        

        for (const auto &e: dict) {
            if (!dp[i+e.size()]) {
                string cs = s.substr(i, e.size());
                if (cs == e) {
                    dp[i+e.size()] = true;
                    breakit(i+e.size());
                }
            }

        }

        
    }
    
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        this->dict = wordDict;
        this->s = s;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        breakit(0);
        return dp[s.size()];
    }
};