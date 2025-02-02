#define INF 1000000000

vector<vector<int>> floyd_warshall(const vector<vector<int>>& edges, int n) {
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (const auto& edge : edges) {
        dist[edge[0]][edge[1]] = edge[2];
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) {
            return {};
        }
    }

    return dist;
}
