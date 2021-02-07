#include <bits/stdc++.h>
#define LLI long long int
using namespace std;


LLI n;
LLI arr[10001];
vector< vector<LLI>> graph(10001);
vector<bool> visited(10001, false);

LLI dfsUtil(LLI u) {
    visited[u] = true;
    LLI res = 0;
    for (LLI i=0;i<(LLI)graph[u].size();i++) {
        if (visited[graph[u][i]] == false) {
            res = res + dfsUtil(graph[u][i]);
        }
    }

    res = res + arr[u];

    return res;
}


void dfs() {
    
    // for (LLI i=0;i<n;i++) {
    //     visited[i] = false;
    // }

    LLI maxim = INT_MIN;
    for (LLI i=0;i<n;i++) {
        LLI curr = 0;
        if (visited[i] == false) {
            curr = dfsUtil(i);
            maxim = max(curr, maxim);
        }
    }

    cout <<  maxim << "\n";
}

int main() {

    cin >> n;
    //LLI graph[n][n];

    for (LLI i=0;i<n;i++) {
        cin >> arr[i];
    }
    
    //memset(graph, 0, sizeof(graph));
    LLI p;
    cin >> p;
    pair<LLI,LLI> pairs[p];
    for (LLI i=0;i<p;i++) {
        cin >> pairs[i].first >> pairs[i].second;

        graph[pairs[i].first-1].push_back(pairs[i].second-1);
        graph[pairs[i].second-1].push_back(pairs[i].first-1);
        // graph[pairs[i].first-1][pairs[i].second-1] = 1;
        // graph[pairs[i].second-1][pairs[i].first-1] = 1;
    }

    

    // for (LLI i=0;i<n;i++) {
    //     for (LLI j=0;j<n;j++) {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    dfs();

    return 0;
}