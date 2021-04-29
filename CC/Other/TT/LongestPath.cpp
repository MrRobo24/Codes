#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> color;
vector<int> tree;
int len = 0;

void solve() {
    vector<int> leaf(n, 0);
    for (int i=0;i<n-1;i++) {
        leaf[tree[i]]++;
    }
    
    for (int i=0;i<n;i++) {
        if (leaf[i] == 0) {
            //leaf node
            // cout << "leaf " << i << "\n";
            int curr = i;
            int c = 0;
            while (true) {
                if (color[curr] == 1) {
                    c++;
                } else {
                    len = max(c, len);
                    c = 0;
                }
                curr--;
                if (curr < 0) {
                    break;
                } else {
                    curr = tree[curr];
                }
            }
            
            len = max(len, c);
        }
    }
}

int main() {
    
    cin >> n;    
    for (int i=0;i<n;i++) {
        int c;
        cin >> c;
        color.push_back(c);
    }
    
    for (int i=0;i<n-1;i++) {
        int v;
        cin >> v;
        tree.push_back(v-1);
    }
    
    solve();
    cout << len << "\n";
    
    return 0;
}
