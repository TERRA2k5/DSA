bool dfs(int vertex, int parent, vector<vector<int>>& adj, vector<bool>& vis){
        if(vis[vertex]) return false;
        
        vis[vertex] = true;
        bool ans = false;
        for(auto& val: adj[vertex]){
            if(val == parent) continue;
            
            if(vis[val]){
                return true;
            }
            ans = ans||dfs(val,vertex,adj,vis);
        }
        return ans;
    }
bool isCycle(int V, vector<vector<int>>& edges) {
    vector<bool> vis(V,false);
    vector<vector<int>> adj(V);

    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    bool ans = false;

    for(int i = 0; i < V ; i++){
        if(vis[i]) continue;
        ans = ans||dfs(i,-1,adj,vis);
    }

    return ans;
}