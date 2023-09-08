#include<bits/stdc++.h>
using namespace std;

const int N = 22;
vector<int> adj[N];
bool visited[N];
int level[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : adj[u])
        {
            if(visited[v] == true) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
    
}

int main()
{
    int n,m; cin>>n>>m;

    for (int i = 0; i < m; i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int k; cin>>k;
    bfs(k);

    int cnt = 0;

    for (int i = 0; i <= n; i++)
    {
        if(level[i] == 1)
        {
            cnt++;
        }
    }
    
    cout<<cnt;
       
    return 0;
}