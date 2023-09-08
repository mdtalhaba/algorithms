#include<bits/stdc++.h>
#define pr pair<int,int>
using namespace std;

const int N = 1e3+5;

bool visited[N][N];
int dis[N][N];
int n,m;

vector<pr> path = {{-1,0},{1,0},{0,-1},{0,1}};

bool isValid(int ci, int cj)
{
    return (ci>=0 && ci<n && cj>=0 && cj<m);
}

void bfs(int si, int sj)
{
    queue<pr> q;
    q.push({si,sj});
    visited[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pr parent = q.front();
        q.pop();
        int pi = parent.first;
        int pj = parent.second;

        for (int i = 0; i < 4; i++)
        {
            pr p = path[i];
            int ci = pi+p.first;
            int cj = pj+p.second;
            
            if(isValid(ci,cj) && !visited[ci][cj])
            {
                visited[ci][cj] = true;
                q.push({ci,cj});
                dis[ci][cj] = dis[pi][pj] + 1;
            }
        }
        
    }
    
}

int main()
{
    cin>>n>>m;

    char ar[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>ar[i][j];
        }
    }

    int si, sj;
    cin>>si>>sj;

    bfs(si,sj);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
       
    return 0;
}