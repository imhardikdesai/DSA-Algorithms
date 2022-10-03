#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) begin(v), end(v)
#define dbg(x) cerr << #x << " " << x << endl;
#define endl '\n'

const int N = 1e5+10;
bool vis[N];
vector<int> graph[N];

void dfs(int vertex){
    vis[vertex]=true;
    cout<<vertex<<endl;
    for(auto child: graph[vertex]){
        cout<<"parent "<<vertex<<", child "<<child<<endl;
        if(vis[child]) continue;
        dfs(child);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
        int v1, v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
    return 0;
}