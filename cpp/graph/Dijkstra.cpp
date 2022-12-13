void dijkstra(vector<vector<pair<ll, int>>> &adj, int n, int src, vector<ll> &dis)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        dis[i] = INF;
    }
    dis[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int u = p.second;
        if (dis[u] != p.first)
        {
            continue;
        }
        for (auto v : adj[u])
        {
            if (dis[v.first] > dis[u] + v.second)
            {
                dis[v.first] = dis[u] + v.second;
                pq.push({dis[v.first], v.first});
            }
        }
    }
}