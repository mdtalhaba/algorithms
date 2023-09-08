#include<bits/stdc++.h>
#define pr pair<int,int>
using namespace std;

const int N = 105;

bool visited[N][N];
int dis[N][N];
int n,m;

vector<pr> path = {{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{1,-2},{-1,2},{1,2}};

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

        for (pr p : path)
        {
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
    int t; cin>>t;
    while (t--)
    {
        cin>>n>>m;
        // char ar[n][m];

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         ar[i][j] = '.';
        //     }
        // }

        int si, sj;
        cin>>si>>sj;

        bfs(si,sj);

        int qi, qj; cin>>qi>>qj;
        if(si==qi && sj==qj) cout<<0<<endl;
        else if(dis[qi][qj] == 0) cout<<-1<<endl;
        else cout<<dis[qi][qj]<<endl;

        n=0, m=0;
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                visited[i][j] = false;
                dis[i][j] = 0;
            }
            
        }
        
    }
    
       
    return 0;
}