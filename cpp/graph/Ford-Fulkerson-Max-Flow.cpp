bool bfs(int n, vector<vector<int>> &r_graph, int s, int t, vector<int> &parent)
{
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && r_graph[u][v] > 0)
            {
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int fordFulkerson(int n, vector<vector<int>> graph, int s, int t)
{
    int u, v;
    vector<vector<int>> r_graph;
    for (u = 0; u < n; u++)
    {
        for (v = 0; v < n; v++)
        {
            r_graph[u][v] = graph[u][v];
        }
    }
    vector<int> parent;
    int max_flow = 0;
    while (bfs(n, r_graph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, r_graph[u][v]);
        }
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            r_graph[u][v] -= path_flow;
            r_graph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}