#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjList(n+1);

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // for undirected graph
    }

    int s; // starting node for BFS
    cin >> s;

    vector<int> dis(n+1, -1); // distance from source node
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while( !q.empty() )
    {
        int u = q.front();
        q.pop();
        for(int v : adjList[u])
        {
            if(dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << "Distance from " << s << " to " << i << " : " << dis[i] << "\n";
    }

    return 0;
}