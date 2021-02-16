#include <bits/stdc++.h>
#define LLI long long
using namespace std;

int main() {

    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LLI t;
    cin >> t;
    while (t--) {
        LLI n;
        cin >> n;
        LLI w[n], l[n];
        unordered_map<LLI,LLI> in;
        unordered_map<LLI,LLI> power;
        

        for (LLI i=0;i<n;i++) {
            cin >> w[i];
            in[w[i]] = i;
        }

        
        for (LLI i=0;i<n;i++) {
            cin >> l[i];
            power[w[i]] = l[i];
        }

        sort(w, w+n);
        LLI pos[n];
        for (LLI i=0;i<n;i++) {
            pos[i] = in[w[i]];
        }

        LLI jumps = 0;
        for (LLI i=1;i<n;i++) {
            LLI prev = pos[i-1];
            if (pos[i] > prev) {
                continue;
            }
            LLI times = (prev-pos[i])/power[w[i]];
            times++;
            jumps += times;
            pos[i] = times*power[w[i]] + pos[i];
        }

        cout << jumps << "\n";

    }

    return 0;
}
