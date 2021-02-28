/*

         0 1 2 3

0        1 1 1 1 = 4
1        0 0 1 1 = 2
2        0 1 1 0 = 2
3        1 1 0 0 = 2



*/
#include <bits/stdc++.h>
#define LLI long long 
#define all(x) x.begin(), x.end()
using namespace std;

int main() {

    LLI t;
    cin >> t;
    while (t--) {
        LLI n, m, k;
        cin >> n >> m >> k;

        vector< vector<LLI> > mat(n);
        vector< pair<LLI, LLI> > p;
        for (LLI i=0;i<n;i++) {
            LLI sum = 0;
            for (LLI j=0;j<m;j++) {
                LLI val;
                cin >> val;
                mat[i].push_back(val);
                sum += val;
            }
            p.push_back({sum, i});
        }


        for (LLI i=0;i<n;i++) {
            for (LLI j=i+1;j<n;j++) {
                if (p[i].first < p[j].first) {
                    swap(p[i], p[j]);
                    mat[i].swap(mat[j]);
                }
            }
        }

        // cout << "\n";
        // for (LLI i=0;i<n;i++) {
        //     cout << p[i].first << " ";
        //     for (LLI j=0;j<m;j++) {
        //         cout << mat[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        LLI i=0, c = 0;
        vector<LLI> curr(m,-1);
        while (k > 0) {
            // cout << i << " i\n";
            while (p[i].first > k) {
                i++;
            }
            
            LLI cs = p[i].first, ci = p[i].second, maxim = INT_MIN;
            
            while (p[i].first == cs) {

                LLI d = 0;
                for (LLI j=0;j<m;j++) {
                    if (mat[i][j] == 1 && curr[j] == 1) {
                        d++;
                    }
                }

                // cout << "D " << d << "\n";

                if (maxim  < p[i].first - d) {
                    maxim = p[i].first - d;
                    ci = p[i].second;
                    // cout << "CHECK\n";
                    curr = mat[i];
                }

                i++;
            }

            k -= maxim;
            cout << ci << "\n";
            c++;
            
        }

        cout << "Count: " << c << "\n";

    }

    return 0;
}

/*

3 6 5
1 1 1 1 0 0
0 0 0 1 0 0
0 0 0 0 1 0


11 7 1
1 1 1 1 0 0 0
0 0 0 1 0 0 0
0 0 0 0 1 0 0
0 0 0 0 0 1 0
1 0 0 0 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 0
1 1 0 0 0 0 0
0 0 1 1 0 0 0
0 0 0 0 1 1 0
0 0 0 0 1 1 0

11 7 2



*/