// Cycle Detection in Undirected Graph using DFS
bool isCyclicDFS(int node, int parent, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (isCyclicDFS(neighbor, node, adjList, visited)) {
                return true;  // Cycle found
            }
        } else if (neighbor != parent) {
            return true;  // Back edge found, cycle detected
        }
    }
    return false;
}

bool hasCycleUndirected(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(i, -1, adjList, visited)) {
                return true;  // Cycle found
            }
        }
    }
    return false;
}


// Cycle Detection in Directed Graph using DFS
bool isCyclicDFSDirected(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (isCyclicDFSDirected(neighbor, adjList, visited, recStack)) {
                return true;  // Cycle found
            }
        } else if (recStack[neighbor]) {
            return true;  // Back edge found, cycle detected
        }
    }
    recStack[node] = false;  // Remove from recursion stack as we're backtracking
    return false;
}

bool hasCycleDirected(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicDFSDirected(i, adjList, visited, recStack)) {
                return true;  // Cycle found
            }
        }
    }
    return false;
}
