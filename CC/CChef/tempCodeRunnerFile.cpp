#include <bits/stdc++.h>
#define LLI unsigned long long
#define MOD 4294967296
using namespace std;

LLI mod(LLI n) { 
    return ( n % (MOD) ); 
}   

class Node {
public:
    LLI sum;
    LLI parent;

    Node() {
        sum = 0;
        parent = 0;
    }

    Node(LLI sum, LLI parent) {
        this->sum = sum;
        this->parent = parent;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI n,q;
    cin >> n >> q;
    LLI weight[n];
    for (LLI i=0;i<n;i++) {
        cin >> weight[i];
    }
    Node parent[n+1];
    parent[0] = Node();
    parent[1] = Node(mod(weight[0] * weight[0]), 0);
    //taking input for edges
    for (LLI i=0;i<n-1;i++) {
        LLI u,v;
        cin >> u >> v;
        parent[v] = Node( mod(parent[u].sum + mod(weight[v-1]*weight[v-1])), u);
    }

    // cout << "NODES: \n";
    // for (LLI i=1;i<n+1;i++) {
    //     cout << i << " " << parent[i].sum << " " << parent[i].parent << "\n";
    // }
    // cout << "\n";


    // while (q--) {
    //     LLI u,v;
    //     cin >> u >> v;
    //     LLI sum = 0;
    //     while (u && v) {
    //         sum = mod( sum + mod(weight[u-1] *  weight[v-1]));
    //         u = parent[u];
    //         v = parent[v];
    //     }

    //     cout << sum << "\n";
    // }

    while (q--) {
        LLI u,v;
        cin >> u >> v;
        LLI sum = 0;
        while (u && v) {

            if (u == v) {
                sum = mod(sum + parent[u].sum);
                break;
            }

            sum = mod( sum + mod(weight[u-1] *  weight[v-1]));
            u = parent[u].parent;
            v = parent[v].parent;
        }

        cout << sum << "\n";
    }



    return 0;
}