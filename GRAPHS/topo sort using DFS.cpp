void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& ans){
    vis[node] = true;
    
    for(auto& val: adj[node]){
        if(!vis[val]){
            dfs(val,vis,adj, ans);
        }
    }
    
    ans.emplace_back(node);
}
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    vector<bool> vis(V, false);
    vector<int> ans;
    for(auto& val: edges){
        adj[val[0]].push_back(val[1]);
    }
    
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i,vis,adj,ans);
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}