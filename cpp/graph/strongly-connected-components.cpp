void fill_order(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &stk)
{
    visited[u] = true;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            fill_order(v, adj, visited, stk);
        }
    }
    stk.push(u);
}

void get_scc(int n, vector<vector<int>> &adj)
{
    stack<int> stk;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            fill_order(i, adj, visited, stk);
        }
    }
    vector<vector<int>> transpose = get_transpose(n, adj); // reverse graph
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();
        if (!visited[u])
        {
            dfs(u, transpose, visited); // normal dfs
        }
    }
}