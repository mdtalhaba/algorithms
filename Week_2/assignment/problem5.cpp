#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adj[N];
bool visited[N];
int cnt = 0;

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

    vector<int> tmp;
    
    for (int i = 0; i < m; i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        tmp.push_back(u);
    }

    vector<int> cc;

    for(int i : tmp)
    {
        if(visited[i]) continue;
        cnt = 0;
        dfs(i);
        if(cnt > 1) cc.push_back(cnt);

    }

    sort(cc.begin(), cc.end());

    for(int i : cc)
    {
        cout<<i<<" ";
    }
    
    return 0;
}