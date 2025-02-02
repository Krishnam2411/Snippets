int primMST(int n, vector<vector<pair<int, int>>>& adjList) {
    vector<int> minEdge(n, INT_MAX); // Stores min weight edge to reach each node
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int mstCost = 0, edgesUsed = 0;

    pq.push({0, 0}); // (cost, node)
    minEdge[0] = 0;

    while (!pq.empty() && edgesUsed < n) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        mstCost += cost;
        edgesUsed++;

        for (auto& [v, weight] : adjList[u]) {
            if (!inMST[v] && weight < minEdge[v]) {
                minEdge[v] = weight;
                pq.push({weight, v});
            }
        }
    }

    return mstCost;
}
