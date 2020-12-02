#include <bits/stdc++.h>
#define LLI long long
using namespace std;

LLI n, m;

LLI distance(vector<vector<LLI> > &adj, vector<vector<LLI> > &cost, LLI s, LLI t) {
  vector<LLI> dist(n, INT_MAX);
  priority_queue< pair<LLI,LLI>, vector< pair<LLI,LLI> >, greater< pair<LLI,LLI> > > h;
  dist[s] = 0;
  h.push({dist[s],s});

  while(!h.empty()) {
    pair<LLI,LLI> minim = h.top();
    LLI u = minim.second;
    h.pop();
    for (LLI i=0;i<adj[u].size();i++) {
        LLI v = adj[u][i];
        //cout <<"U: "<< u+1 <<"V: " << v+1 << "\n";
        if (dist[v] > dist[u] + cost[u][i]) {
            dist[v] = dist[u] + cost[u][i];
            //cout << "DIST: " << dist[v] << "\n";
            h.push({dist[v], v});
        }
    }
  }

  return (dist[t] == INT_MAX? -1 : dist[t]);
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cin >> n >> m;
    vector<vector<LLI> > adj(n, vector<LLI>());
    vector<vector<LLI> > cost(n, vector<LLI>());
    
    for (LLI i = 0; i < m; i++) {
        LLI x, y, w;
        cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }

    cout << "Enter the starting and ending vertices: ";
    LLI s, t;
    cin >> s >> t;
    s--, t--;
    cout << "Shortest distance is: " <<distance(adj, cost, s, t);
  return 0;
}