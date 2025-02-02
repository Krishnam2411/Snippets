struct Edge {
    int u, v, weight;
};

vector<int> bellman_ford(int src, const vector<Edge>& edges, int n)
{
    vector<int> dist(n, INF);
    dist[src] = 0;

    for (int i = 1; i < n; ++i)
    {
        for (const auto& edge : edges)
        {
            if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v])
            {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    for (const auto& edge : edges)
    {
        if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v])
        {
            // Negative cycle detected!
            return {};
        }
    }

    return dist;
}