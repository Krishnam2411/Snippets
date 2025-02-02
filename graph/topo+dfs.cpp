void dfs(int src, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& stk) {
    visited[src] = true;
    
    for (int neighbor : adj[src]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, stk);
        }
    }
    
    stk.push_back(src);
}

vector<int> TopoSort(const vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    vector<int> stk, order;
    stk.reserve(n);

    for (int node = 0; node < n; ++node) {
        if (!visited[node]) {
            dfs(node, adj, visited, stk);
        }
    }

    order.reserve(n);
    for (auto it = stk.rbegin(); it != stk.rend(); ++it) {
        order.push_back(*it);
    }

    return order;
}
