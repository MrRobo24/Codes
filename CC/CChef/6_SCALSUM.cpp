#include <bits/stdc++.h>
#define LLI unsigned long long
using namespace std;

LLI power(LLI base, LLI exp) { 
    if (exp == 0) 
        return 1; 
  
    if (exp == 1) 
        return base; 
  
    LLI t = power(base, exp / 2); 
    t = (t * t); 
  
    if (exp % 2 == 0) 
        return t; 
    else
        return (base * t); 
} 

LLI MOD = power(2,32);

LLI mod(LLI n) { 
    return ( n % (MOD) ); 
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

    while (q--) {
        LLI u,v;
        cin >> u >> v;
        LLI sum = 0;
        while (u && v) {
            sum = mod(mod(sum) + mod( mod(weight[u-1]) * mod(weight[v-1]) ));
            u = parent[u];
            v = parent[v];
        }

        cout << sum << "\n";
    }

}