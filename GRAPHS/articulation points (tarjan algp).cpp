int timer = 1;
void dfs(int node, vector<vector<int>>& adj, vector<int>& tim , vector<int>& low, 
vector<bool>& vis, int parent, vector<int>& ans, vector<bool>& mark){
    vis[node] = true;
    tim[node] = timer;
    low[node] = timer++;
    
    int cntChild = 0;
    
    for(auto& val: adj[node]){
        if(val == parent) continue;
        
        if(vis[val]){
            // low update to time instead of low for visited 
            low[node] = min(low[node], tim[val]);
            continue;
        }
        
        dfs(val, adj, tim, low, vis, node, ans, mark);
        
        // greedly update low
        low[node] = min(low[node], low[val]);
        
        // add only id val can reach a time before node (not equal)
        if(low[val] >= tim[node] && parent != -1){ 
            mark[node] = true;
        }
        
        cntChild++;
    }
    
    // for checking parent node if thier exist multiple compnent child of root
    if(parent == -1 && cntChild > 1){
        ans.push_back(node);
    }
}
vector<int> articulationPoints(int V, vector<vector<int>>& edges){
    
    vector<vector<int>> adj(V);
    
    for(auto& val: edges){
        adj[val[1]].push_back(val[0]);
        adj[val[0]].push_back(val[1]);
    }
    vector<int> ans;
    vector<int> tim(V);
    vector<int> low(V);
    vector<bool> vis(V, false);
    vector<bool> mark(V, false);
    
    // in case for disconnected graph
    for(int i = 0; i < V; i++){
        if(!vis[i]) dfs(i,adj,tim,low,vis,-1,ans,mark);
    }
    
    for(int i = 0; i < V; i++){        
        if(mark[i]){
            ans.push_back(i);
        }
    }
    
    if(ans.size() == 0) return {-1};
    return ans;
       
}