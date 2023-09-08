#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];
int cnt = -1;

void dfs(int u)
{
    visited[u] = true;
    cnt++;
    for(int v : adj[u])
    {
        if(visited[v]) continue;
        dfs(v);
    }
}

int main()
{
    int n,m; cin>>n>>m;
    
    for (int i = 0; i < m; i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }

    int k; cin>>k;

    dfs(k);

    cout<<cnt;
    
    return 0;
}