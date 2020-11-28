#include <bits/stdc++.h>
#define LLI long long
using namespace std;
LLI V, E;
LLI graph[100][100];
stack<LLI> ans;

void topoSortUtil(LLI u, LLI* visited) {
    visited[u] = 1;
    for (LLI v=0;v<V;v++) {
        // cout << graph[u][v] << "G " << visited[v] << "vis " << " \n";
        if (graph[u][v] && !visited[v]) {
            // cout << u << " " << v << "\n";
            topoSortUtil(v, visited);
        }
    }

    ans.push(u);
}

void topoSort() {
    LLI visited[V] = {0};
    for (LLI i=0;i<V;i++) {
        if (!visited[i]) {
            topoSortUtil(i, visited);
        }
    }

    cout << "TOPOLOGICAL SORT: ";
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << "\n";
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
    }

    topoSort();

    return 0;
}