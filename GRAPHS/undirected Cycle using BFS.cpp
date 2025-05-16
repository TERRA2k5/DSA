bool isCycle(int V, vector<vector<int>>& edges) {
        
    vector<vector<int>> adj(V);
    
    for(auto& val: edges){
        adj[val[0]].push_back(val[1]);
        adj[val[1]].push_back(val[0]);
    }
    
    vector<bool> vis(V , false);
    // vis[0].first = true;
    queue<pair<int,int>> q;
    for(int i = 0; i < V; i++){
        if(vis[i]) continue;
        q.push({i,-1});
    
        while(!q.empty()){
            int vertex = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            vis[vertex] = true;
            
            for(auto& val: adj[vertex]){
                if(val == parent) continue;
                if(vis[val]){
                    return true;
                }
                q.push({val,vertex});
            }
        }
    }
        
    return false;
}