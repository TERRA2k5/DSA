vector<int> bellman_ford(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    // if not reachable then distance is 1e8
    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto& val : edges) {
            int u = val[0];
            int v = val[1];
            int wt = val[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto& val : edges) {
        int u = val[0];
        int v = val[1];
        int wt = val[2];

        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return vector<int>{-1}; 
        }
    }

    return dist;
}
