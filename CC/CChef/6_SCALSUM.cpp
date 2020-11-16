// AC & TLE
#include <bits/stdc++.h>
#define LLI unsigned long long
#define MOD 4294967296
using namespace std;



LLI mod(LLI n) { 
    return (n % MOD); 
}   

int main() {

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    LLI n,q;
    cin >> n >> q;
    LLI weight[n];
    for (LLI i=0;i<n;i++) {
        cin >> weight[i];
    }
    LLI parent[n+1];
    LLI prev[n+1];
    parent[0] = 0;
    parent[1] = 0;
    prev[0] = 0;
    prev[1] = mod(weight[0] * weight[0]);
    //taking input for edges
    LLI queries[n-1][2];
    for (LLI i=0;i<n-1;i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    for (LLI i=0;i<n-1;i++) {
        LLI u, v;
        u = queries[i][0];
        v = queries[i][1];
        parent[v] = u;
        prev[v] = mod(prev[u] + mod(weight[v-1]*weight[v-1]));
    }

    while (q--) {
        LLI u,v;
        cin >> u >> v;
        LLI sum = 0;
        while (u && v) {

            if (u == v) {
                sum = mod(sum + prev[u]);
                break;
            }

            sum = mod(mod(sum) + mod( mod(weight[u-1]) * mod(weight[v-1]) ));
            u = parent[u];
            v = parent[v];
        }

        cout << sum << "\n";
    }

}