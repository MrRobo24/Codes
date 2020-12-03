#include<bits/stdc++.h>
#define LLI long long
using namespace std;

vector< vector<LLI> > graph(100000);
LLI n, p;


void dfsUtil(vector<bool> &visited, LLI u) {
    visited[u] = true;
    for (LLI i=0;i<graph[u].size();i++) {
        if (!visited[graph[u][i]]) {
            dfsUtil(visited, graph[u][i]);
        }
    }
}

LLI dfs() {
    vector<bool> visited(n, false);
    LLI c = 0;
    for (LLI i=0;i<n;i++) {
        if (!visited[i]) {
            c++;
            dfsUtil(visited, i);
        }
    }
    
    return c;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p;
    LLI in[n][2];
    LLI c = 0;
    for (LLI i=0;i<p;i++) {
        cin >> in[i][0] >> in[i][1];
    }
    
    for (LLI i=0;i<p;i++) {
        LLI a = in[i][0], b = in[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    
	cout << dfs() << "\n";

    return 0;
}