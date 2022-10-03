// Program to find shortest path from a every node to all other nodes
// -----Floyd Warshall Algorithm-----
//      ------------------

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, q;
    cin>>n>>m>>q;
    int a[n][n];
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            a[i][j] = INT_MAX;
        }
    }
    for(int i = 0;i < n;i++)
    {
        a[i][i] = 0;
    }
    for(int i = 0;i < m;i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        x--;y--;
        a[x][y] = min(a[x][y], z);
        a[y][x] = min(a[x][y], z);
    }
    for(int k = 0;k < n;k++)
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(a[i][k] == INT_MAX or a[k][j] == INT_MAX)
                {
                    continue;
                }
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    while(q--)
    {
        int x, y;
        cin>>x>>y;
        x--;y--;
        if(a[x][y] == INT_MAX)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<a[x][y]<<endl;
        }
    }
}

int main(){
    solve();
    return 0;
}