void topoSort(int node, vector<bool>& vis, stack<int>& st, vector<vector<pair<int,int>>>& adj){
    vis[node] = true;
    
    for(auto& val: adj[node]){
        if(!vis[val.first]){
            topoSort(val.first,vis,st,adj);
        }
    }
    
    st.push(node);
}
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    // code here
    vector<int> wt(V,INT_MAX);
    vector<vector<pair<int,int>>> adj(V);
    
    for(auto& val: edges){
        adj[val[0]].push_back({val[1],val[2]});
    }
    
    vector<bool> vis(V, false);
    stack<int> st;
    
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            topoSort(i,vis,st,adj);
        }
    }
    
    wt[0] = 0;
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        // cout << node<<endl;
        if(wt[node] == INT_MAX) continue;
        for(auto& it: adj[node]){
            int next = it.first;
            int dist = it.second;
            
            if(wt[next] > wt[node]+dist){
                wt[next] = wt[node]+dist;
                // cout << node<<endl;
            }
        }
    }
    
    for(int i = 0; i < V; i++) {
        if(wt[i] == INT_MAX) wt[i] = -1;
    }

    
    return wt;
}