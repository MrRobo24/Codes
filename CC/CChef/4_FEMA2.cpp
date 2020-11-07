//AC
#include <bits/stdc++.h>
#define LLI long long
using namespace std;

void solve(string s, LLI k) {
    LLI  p = 0, c = 0;
    LLI n = s.size();

    LLI sh[n+1], bk[n+1];
    sh[0] = 0;
    bk[0] = 0;

    vector<LLI> i;
    vector<LLI> m;

    for (LLI j=0;j<n;j++) {
        char ch = s[j];
        sh[j+1] = sh[j];
        bk[j+1] = bk[j];
        if (ch == ':') {
            sh[j+1]++;
        } else if (ch == 'X') {
            bk[j+1]++;
        } else if (ch == 'I') {
            i.push_back(j);
        } else if (ch == 'M') {
            m.push_back(j);
        }
    }

    LLI mp = 0, ip = 0;
    while(ip < i.size() && mp < m.size()) {
            // cout << "CHECK\n";
            LLI iron = i[ip], magnet = m[mp], sheet = 0, block = 0;
            // for (LLI l = 0; l < i.size(); l++) {
            //     cout << i[l] << " ";
            // }
            // cout << "\n";
            // for (LLI l = 0; l < m.size(); l++) {
            //     cout << m[l] << " ";
            // }
            // cout << "\n";
            
            // cout << "P TEMP " << p << "\n";
            // for (LLI l = 0;l<n+1;l++) {
            //     cout << sh[l] << " ";
            // }
            // cout << "\n";
            // for (LLI l = 0;l<n+1;l++) {
            //     cout << bk[l] << " ";
            // }
            // cout << "\n";
            block = abs(bk[magnet] - bk[iron]);
            sheet = abs(sh[magnet] - sh[iron]);
            p = k + 1 - abs(iron - magnet) - sheet;
            if (iron < magnet) {    
                if (!block && p > 0) {
                    c++;
                    //m.erase(m.begin());
                    mp++;
                }
                //i.erase(i.begin());
                ip++;

            } else {
                if (!block && p > 0) {
                    c++;
                    //i.erase(i.begin());
                    ip++;
                }
                //m.erase(m.begin());
                mp++;
            }
            // cout << "P: " << p << "\n";
            // cout << "C: " << c << "\n\n";
    }

    cout << c << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI t;
    cin >> t;
    while (t--) {
        LLI n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        solve(s, k);
    }

    return 0;
}
