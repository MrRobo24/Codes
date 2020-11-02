#include <bits/stdc++.h>
#define LLI long long
using namespace std;
LLI dp[101][101];
LLI MAX_MASK;
/*

    mask = 0000000
    11111 = 2^5 + 2^4 + 2^3 + 2^2 + 2^1 + 2^0 = 2^6 - 1

*/

LLI TSPCost(vector< vector<LLI> > &mat, LLI u, LLI n, LLI mask) {

    if (mask == MAX_MASK) {
        //cout << "ALL VISITED: " << "\n";
        return mat[u][0];
    }


    if (dp[u][mask] != -1) {
        //cout << "DP VAL AVAIL AT: " << u << " " << mask << " = " << dp[u][mask] << "\n";
        return dp[u][mask];
    }

    LLI minimCost = INT_MAX;
    for (LLI i=0;i<n;i++) {
        if (mat[u][i] != -1 && (mask&(1<<i)) == 0) {
            
            LLI currCost = mat[u][i] + TSPCost(mat, i, n, (mask|(1<<i)) );    
            //cout << "MASK " << mask << " CURR COST  = " <<  currCost < "\n";
            minimCost = min(minimCost, currCost);
        }
    }

    //cout << "ASSIGN AND RET DP VAL " << minimCost << "\n\n";
    return dp[u][mask] = minimCost;
}

/*

0 2 5 10
2 0 3 12
5 3 0 6
10 12 6 0


0000



*/


int main() {
    LLI n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    vector< vector<LLI> > mat(n);
    memset(dp, -1, sizeof(dp));
    MAX_MASK = (1<<n)-1;
    cout << "Enter the adjacency matrix for the graph: ";
    for (LLI i=0;i<n;i++) {
        for (LLI j=0;j<n;j++) {
            LLI cost;
            cin >> cost;
            mat[i].push_back(cost);
        }
    }
    
    cout << "Minimum cost is: " << TSPCost(mat, 0, n, 0);

}