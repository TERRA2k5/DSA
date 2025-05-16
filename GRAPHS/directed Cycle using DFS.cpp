bool dfs(int node, vector<int>& vis, vector<int>& path, vector<vector<int>>& adj){
    if(path[node] == 1 && vis[node] == 1) return true;
    else if(vis[node] == 1) return false;
    
    vis[node] = 1; 
    path[node] = 1;
    
    for(auto& val: adj[node]){
        if(dfs(val,vis,path,adj)) return true;
    }
    
    path[node] = 0;
    return false;
}
bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<int> vis(V);
    vector<int> path(V);
    
    
    vector<vector<int>> adj(V);
    for(auto& val: edges){
        adj[val[0]].push_back(val[1]);
    }
    
    for(int i = 0; i < V; i++){
        if(dfs(i,vis,path,adj)) return true;
    }
    
    return false;
}