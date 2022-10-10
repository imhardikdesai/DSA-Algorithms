#include<bits/stdc++.h>
using namespace std;

void Bfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeBfs) {
	queue<int> q;
	q.push(node);
	vis[node] = 1;
	while(!q.empty()) {
		int fronT = q.front();
		q.pop();
		storeBfs.push_back(fronT);
		for(auto it : adj[fronT]) {
			if(!vis[it]) {
				vis[it] = 1;
				q.push(it);
			}
		}
	}
}

vector<int> printBfsTraversal(int n, vector<int> adj[]) {
	vector<int> storeBfs;
	vector<int> vis(n, 0);
	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			Bfs(i, vis, adj, storeBfs);
		}
	}
	return storeBfs;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(auto it : printBfsTraversal(n, adj)) {
		cout << (it) << " ";
	}
}
/*
8 13
0 1
0 3
1 2
1 3
2 3
2 4
2 7
3 4
4 5
4 6
4 7
5 6
6 7
*/

/*
Input 1: 5 nodes & 7 edges
5 7
0 1
0 4			(0)--(1)--\
1 2			 |   /|    \
1 3			 |  / |    (2)
1 4			 | /  |    /
2 3			(4)--(3)--/
3 4
Output 1:
0 1 4 2 3

Input 2: 9 nodes & 9 edges
9 9
0 1
1 2				 (2)--(3)
1 7			     /	    \
2 3		  (0)--(1)		(4)--(5)
3 4			     \	    /
4 5    			 (7)--(8)
4 8					    \
6 8					    (6)
7 8
Output 2:
0 1 2 7 3 8 4 6 5 

*/
