// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
stack<int> ans;

void topoUtil(int u, bool* visited, vector<int> adj[]) {
    visited[u] = true;
    for (int i=0;i<adj[u].size();i++) {
        if (!visited[adj[u][i]]) {
            topoUtil(adj[u][i], visited, adj);
        }
    }
    ans.push(u);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    bool visited[V];
    for (int i=0;i<V;i++) {
        visited[i] = false;
    }
    
    for (int i=0;i<V;i++) {
        if (!visited[i]) {
            topoUtil(i, visited, adj);
        }
    }
    vector<int> ret;
    while (!ans.empty()) {
        ret.push_back(ans.top());
        ans.pop();
    }
    
    return ret;
}
