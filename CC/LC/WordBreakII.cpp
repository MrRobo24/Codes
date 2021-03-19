class Solution {
public:
    
    vector<string> dict;
    string s;
    vector<string> ret;
    
    void breakit(int i, string curr) {
        if (i == s.size()) {
            ret.push_back(curr.substr(0, curr.size()-1));
            return;
        }
        
        for (const auto &e: dict) {
            string cs = s.substr(i, e.size());
            if (cs == e) {
                breakit(i+e.size(), curr + e + " ");
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->dict = wordDict;
        this->s = s;
        breakit(0, "");
        return ret;
    }
};