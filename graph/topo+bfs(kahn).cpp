vector<int> TopoSort(const vector<vector<int>>& adj, int n) {
    vector<int> indegree(n, 0);
    
    for (int node = 0; node < n; ++node) {
        for (int neighbor : adj[node]) {
            indegree[neighbor]++;
        }
    }

    queue<int> q;
    
    for (int node = 0; node < n; ++node) {
        if (indegree[node] == 0) {
            q.push(node);
        }
    }

    vector<int> order;
    order.reserve(n);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int neighbor : adj[node]) {
            if (--indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (order.size() != n) {
        return {};  // Cycle detected, returning empty vector
    }

    return order;
}
