#include <bits/stdc++.h>
#define LLI long long
using namespace std;
LLI V, E;
LLI graph[100][100];
vector<LLI> ans;

void dfsUtil(LLI u, LLI* visited) {
    ans.push_back(u);
    // cout << "PUSHED " << u << "\n";
    visited[u] = 1;
    for (LLI v=0;v<V;v++) {
        // cout << graph[u][v] << "G " << visited[v] << "vis " << " \n";
        if (graph[u][v] && !visited[v]) {
            // cout << u << " " << v << "\n";
            dfsUtil(v, visited);
        }
    }
}

void dfs() {
    LLI visited[V] = {0};
    for (LLI i=0;i<V;i++) {
        if (!visited[i]) {
            dfsUtil(i, visited);
        }
    }

    cout << "DFS: ";
    for (LLI i=0;i<V;i++) {
        cout << ans[i] << " ";
    }
}


int main() {
    // cout << "Enter the total number of vertices: ";
    cin >> V;
    memset(graph, 0, sizeof(graph));
    // cout << "Enter the number of edges: ";
    cin >> E;
    // cout << "Enter all the edges one by one: ";
    for (LLI i=0;i<E;i++) {
        LLI u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // for (LLI i=0;i<V;i++) {
    //     for (LLI j=0;j<V;j++) {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    dfs();

    return 0;
}