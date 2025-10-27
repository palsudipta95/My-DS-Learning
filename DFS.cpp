#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
vector<int> visited;
void dfs(int s)
{
    visited[s] = 1;
    cout << s << " ";
    for(int i = 0; i < adjList[s].size(); i++)
    {
        int v = adjList[s][i];
        if(!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    adjList = vector<vector<int>>(n+1);
    visited = vector<int>(n+1, 0);
    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    dfs(1); 

    return 0;
}