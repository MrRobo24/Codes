#include <bits/stdc++.h> 
#define LLI long long
using namespace std; 

vector<pair<LLI, LLI> > G[100000]; 
unordered_map<LLI, char> name;

void insertEdge(LLI from, LLI to, LLI wt) { 
	G[from].push_back({ to, wt });
    G[to].push_back({from, wt}); 
} 

void printDistance(LLI dis[], LLI V, LLI parent[]) { 
    stack <char> ans;
    ans.push('Y');
    LLI u = 15;
    while (u != -1) {
        ans.push( name[parent[u]]);
        u = parent[u];
    }

    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }

} 

void shortestPathFunc(LLI S, LLI V) { 

	LLI dis[V + 1]; 
    LLI parent[V + 1] = {-1};

	bool inQueue[V + 1] = { false }; 

	for (LLI i = 0; i <= V; i++) { 
		dis[i] = INT_MAX; 
	} 
	dis[S] = 0; 

	queue<LLI> q; 
	q.push(S); 
	inQueue[S] = true; 

	while (!q.empty()) { 

		LLI u = q.front(); 
		q.pop(); 
		inQueue[u] = false; 

		for (LLI i = 0; i < G[u].size(); i++) { 

			LLI v = G[u][i].first; 
			LLI weight = G[u][i].second; 

			if (dis[v] > dis[u] + weight) { 
				dis[v] = dis[u] + weight; 
                parent[v] = u;
				if (!inQueue[v]) { 
					q.push(v); 
					inQueue[v] = true; 
				} 
			} 
		} 
	} 

	printDistance(dis,V,parent);
} 

int main() 
{ 

    LLI a,b,c,d;
    cin >> a >> b >> c >> d;
    name[1] = 'X';
    name[2] = 'A';
    name[3] = 'B';
    name[4] = 'F';
    name[5] = 'E';
    name[6] = 'C';
    name[7] = 'D';
    name[8] = 'G';
    name[9] = 'H';
    name[10] = 'L';
    name[11] = 'M';
    name[12] = 'I';
    name[13] = 'J';
    name[14] = 'O';
    name[15] = 'Y';
    name[16] = 'K';
	LLI V = 16; 
	LLI S = 1; 

	insertEdge(1, 2, 1); 
	insertEdge(1, 3, 1);
    insertEdge(2, 4, 1);
    insertEdge(3, 7, 1);
    insertEdge(5, 8, 2);
    insertEdge(6, 9, 2);
    insertEdge(1, 5, b);
    insertEdge(1, 6, 4);
    insertEdge(4, 10, a);
    insertEdge(7, 9, 2);
    insertEdge(10, 11, 2);
    insertEdge(9, 12, c);
    insertEdge(9, 13, 1);
    insertEdge(11, 14, 3);
    insertEdge(11, 15, 2);
    insertEdge(12, 15, 3);
    insertEdge(13, 16, d);
    insertEdge(16, 15, 3);
    insertEdge(14, 15, 1); 
	
	shortestPathFunc(S, V); 

	return 0; 
} 