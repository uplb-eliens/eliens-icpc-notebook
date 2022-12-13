void bellman_ford(vector<vector<int>> &edges, int n, int m, int src, vector<int> &dis)
{
    for (int i = 0; i < n; i++)
    {
        dis[i] = INF;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0], v = edges[j][1], w = edges[j][2];
            if (dis[u] < INF)
            {
                dis[v] = min(dis[v], dis[u] + w);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        if (dis[u] < INF && dis[u] + w < dis[v])
        {
            cout << "The graph contains a negative cycle." << '\n';
        }
    }
}