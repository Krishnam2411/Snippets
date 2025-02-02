#define INF 1000000000

vector<int> dijkstra(int src, const vector<vector<pair<int, int>>>& adj, int n) {
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [curr_dist, node] = pq.top();
        pq.pop();

        if (curr_dist > dist[node]) continue;

        for (auto [next_node, weight] : adj[node]) {
            if (dist[node] != INF && dist[node] + weight < dist[next_node]) {
                dist[next_node] = dist[node] + weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    return dist;
}
