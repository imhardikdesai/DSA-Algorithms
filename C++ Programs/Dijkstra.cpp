// Program to find shortest path from a particular node to all other nodes
// -----Dijkstra Algorithm-----
//      ------------------

#include <bits/stdc++.h>
using namespace std;

vector<int>dist, visited;
vector<vector<pair<int, int>>>adj;
void dijkstra(int src)
{
	multiset<pair<int, int>>mset;
	mset.insert({0, src});
	dist[src] = 0;
	while(mset.size())
	{
		auto node = *mset.begin();
		int v = node.second;
		int dst = node.first;
		mset.erase(mset.begin());
		if(visited[v] == 1)
		{
			continue;
		}
		visited[v] = 1;
		for(auto i:adj[v])
		{
			int child_v = i.first;
			int wt = i.second;
			if(dist[v] + wt < dist[child_v])
			{
				dist[child_v] = dist[v] + wt;
				mset.insert({dist[child_v], child_v});
			}
		}
	}
}

void solve(){
    // n -> number of nodes
    // m -> number of edges
    // src -> source node;
    int n, m, src;
    cin>>n>>m>>src;
    dist.clear();
    dist.resize(n + 1, INT_MAX);
    visited.clear();
    visited.resize(n + 1, 0);
    adj.clear();
    adj.resize(n + 1);
    for(int i = 0;i < m;i++){
        int x, y, z;
        cin>>x>>y>>z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    dijkstra(src);
    // output the shortest path from src to any other node
}

int main(){
    solve();
    return 0;
}