
struct UnionFind {
    vector<int> parent, rank;
    
    UnionFind(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }

    bool unionByRank(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if (rootU == rootV) return false;
        if (rank[rootU] < rank[rootV]) swap(rootU, rootV);
        parent[rootV] = rootU;
        if (rank[rootU] == rank[rootV]) rank[rootU]++;
        return true;
    }
};

int kruskalMST(int n, vector<pair<int, pair<int, int>>>& edges) {
    sort(edges.begin(), edges.end()); // Sort by weight
    UnionFind uf(n);
    int mstCost = 0, edgesUsed = 0;

    for (auto& [weight, uv] : edges) {
        auto [u, v] = uv;
        if (uf.unionByRank(u, v)) {
            mstCost += weight;
            edgesUsed++;
        }
        if (edgesUsed == n - 1) break;
    }

    return mstCost;
}
