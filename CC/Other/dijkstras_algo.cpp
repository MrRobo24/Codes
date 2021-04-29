#include <bits/stdc++.h>
#define LLI long long

using namespace std;
LLI n, e;
vector< vector< pair<LLI, LLI> > > g;


void solve(LLI src) {
    vector<LLI> dist(n, INT_MAX);
    vector<bool> fin(n, false);

    priority_queue< pair<LLI, LLI>, vector< pair<LLI, LLI> >, greater< pair<LLI, LLI> > > pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        LLI u = pq.top().second; // taking out the vertex with shortest edge weight
        pq.pop();
        fin[u] = true;

        for (const auto &e: g[u]) {
            
            LLI v = e.first;
            LLI w = e.second;

            if (!fin[v] && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Distances from source are:\n";
    for (LLI i=0;i<n;i++) {
        cout << i << " " << dist[i] << "\n";
    }

}


void init() {
    cin >> n >> e;
    g = vector< vector< pair<LLI, LLI> > > (n, vector< pair<LLI, LLI>>() ); 

    for (LLI i=0;i<e;i++) {
        LLI u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    LLI src;
    cin >> src;
    solve(6);

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    return 0;

}
