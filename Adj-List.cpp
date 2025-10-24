// (Unweighted) Adjacency List representation of a Graph

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjList(n);

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // for undirected graph
    }
    for(int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for(int j =0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}


// (Weighted) Adjacency List representation of a Graph

#include<bits/stdc++.h>
using namespace std;    

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adjList[n];

    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); 
    }
    for(int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for(int j =0; j < adjList[i].size(); j++)
        {
            cout << "(" << adjList[i][j].first << ", " << adjList[i][j].second << ") ";
        }
        cout << "\n";
    }

    return 0;
}