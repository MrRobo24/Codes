// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

 // } Driver Code Ends


//User function Template for C++

class Trie {
public:
    Trie* child[26];
    vector<int> ending;
    Trie() {
        for (int i=0;i<26;i++) {
            child[i] = NULL;
        }
    }

    void insert(string word, int pos) {
        Trie* curr = this;
        for (auto c: word) {
            if (curr->child[c-'a'] == NULL) {
                curr->child[c-'a'] = new Trie();
            }
            curr = curr->child[c-'a'];
        }
        
        curr->ending.push_back(pos);
    }

    vector<string> search(string word, vector<string> &string_list, vector<bool> &visited) {
        Trie* curr = this;
        vector<string> line;
        
        for (auto c: word) {
            if (curr == NULL || curr->child[c-'a'] == NULL) {
                return line;
            }
            curr = curr->child[c-'a'];
        }
        
        if (curr != NULL && curr->ending.size() != 0) {
            
            for (auto e: curr->ending) {
                line.push_back(string_list[e]);
                visited[e] = true;
            }
        }
        
        return line;
    }
    
    void getGroups(vector<string> string_list, vector< vector<string> > &ans) {
        int c = 0;
        vector<bool> visited(string_list.size(), false);
        for (auto s: string_list) {
            if (visited[c++] == false) {
                string t = s;
                sort(t.begin(), t.end());
                ans.push_back(search(t, string_list, visited));
            }
        }
    }
    
    
    
    
};



vector<vector<string> > Anagrams(vector<string>& string_list) {
    int c = 0;
    Trie* root = new Trie();
    for (auto s: string_list) {
        string t = s;
        sort(t.begin(), t.end());
        root->insert(t, c++);
    }

    vector< vector<string> > ans;
    root->getGroups(string_list, ans);
    return ans;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends