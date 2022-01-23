//
//  DownloadMoreRAM.cpp
//  codes
//
//  Created by Arpit Suman on 23/01/22.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        vector<int> b;
        for (int i=0;i<n;i++) {
            int val;
            cin >> val;
            a.push_back(val);
        }
        
        for (int i=0;i<n;i++) {
            int val;
            cin >> val;
            b.push_back(val);
        }
        
        for (int i=0;i<n-1;i++) {
            for (int j=0;j<n-i-1;j++) {
                if (a[j+1] < a[j]) {
                    swap(a[j+1], a[j]);
                    swap(b[j+1], b[j]);
                }
            }
        }
        
        int i = 0, res = k;
        while (i < n) {
            if (a[i] < res) {
                res += b[i];
                i++;
            } else {
                break;
            }
        }
        
        cout << res << "\n";
        return 0;
    }
}
