#include <bits/stdc++.h>
#define LLI unsigned long long
using namespace std;

LLI MOD = pow(2,32);

struct hashPair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return (hash1 ^ hash2); 
    } 
};

LLI mod(LLI n) { 
    return ( n & (MOD - 1) ); 
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
    parent[0] = 0;
    parent[1] = 0;
    //taking input for edges
    for (LLI i=0;i<n-1;i++) {
        LLI u,v;
        cin >> u >> v;
        parent[v] = u;
    }

    unordered_map< pair<LLI,LLI>, LLI, hashPair> storage;

    while (q--) {
        LLI u,v,uc,vc;
        cin >> u >> v;
        uc = u;
        vc = v;
        LLI sum = 0;

        if (storage[{u,v}]) {
            sum = storage[{u,v}];
        } else {

            while (u && v) {

                // cout << "U AND V " << u << " " << v << "\n";
                // cout << "SQR " << weightsqr[u-1] << "\n";
                // cout << "WEIGHTS " << weight[u-1] << " " << weight[v-1] << "\n";
                if (storage[{u,v}]) {
                    sum = mod(sum + storage[{u,v}]);
                    break;
                }

                sum = mod(sum + mod(weight[u-1] * weight[v-1]));
                u = parent[u];
                v = parent[v];   
                // cout << "SUM " << sum << "\n";
                
            }

            storage[{uc,vc}] = sum;
        }

        cout << sum << "\n";
    }

}
