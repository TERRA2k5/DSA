int timer = 1;
void dfs(int node, int parent, vector<bool>& vis, vector<vector<int>>& adj,
vector<int>& timee, vector<int>& low, vector<vector<int>>& bridges){
    
    vis[node] = true;
    timee[node] = timer;
    low[node] = timer++;
    
    for(auto& val: adj[node]){
        if(val == parent) continue;
        
        if(!vis[val]){
            dfs(val,node,vis,adj,timee,low,bridges);
            
            // updating low after dfs of val is done
            low[node] = min(low[node],low[val]);
            
            // checking if this can be a bridge
            if(low[val] > timee[node]){ 
                bridges.push_back(vector<int>{val,node});
            }
        }
        else{
            // updating low after dfs of val is done
            low[node] = min(low[node],low[val]);
            // no need to check for bridge since it must have reach if other way exist
        }
        
    }
}
vector<vector<int>> tarjan(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adj(n);

    for(auto& val: connections){
        adj[val[0]].push_back(val[1]);
        adj[val[1]].push_back(val[0]);
    }

    vector<vector<int>> bridges;
    vector<bool> vis(n, false);
    
    // time is max time required to reach that edge
    vector<int> timee(n);
    
    // low is node's least time required adjecnent
    // a node of low = x can reach all other node with time >= x
    vector<int> low(n);
    
    dfs(0,-1,vis,adj,timee,low,bridges);
    
    return bridges;
}