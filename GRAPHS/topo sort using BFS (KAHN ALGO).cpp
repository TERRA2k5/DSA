vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }

    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return ans;
}
