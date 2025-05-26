void dfs1(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st){
    vis[node] = true;
    
    for(auto& val: adj[node]){
        if(!vis[val]){
            dfs1(val,adj,vis,st);
        }
    }
    // prepare finishing order
    st.push(node);
}
void dfs2(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& ssc){
    vis[node] = true;
    
    // making this particular component scc
    ssc.push_back(node);
     
    for(auto& val: adj[node]){
        if(!vis[val]){
            // add non visited to component
            dfs2(val,adj,vis,ssc);
        }
    }
}
int kosaraju(vector<vector<int>> &adj) {
    int n = adj.size();
    
    vector<bool> vis(n, false);
    stack<int> finishing;
    
    // prepare finishing order
    for(int i = 0; i < n; ++i) {
        if(!vis[i]) dfs1(i, adj, vis, finishing);
    }
    
    // reverse all the edges
    vector<vector<int>> newAdj(n);
    for(int i = 0; i < n; i++){
        for(auto& val: adj[i]){
            newAdj[val].push_back(i);
        }
    }
    
    
    vector<vector<int>> scc;
    int cntSSC = 0;
    
    vis.assign(n, false);
    
    while(!finishing.empty()){
        int node = finishing.top();
        finishing.pop();
        
        if(!vis[node]){
            vector<int> temp;
            cntSSC++;
            
            dfs2(node,newAdj,vis,temp);
            
            // making scc by discontinuation in components
            sort(temp.begin(),temp.end());
            scc.push_back(temp);
        }
    }
    sort(scc.begin(),scc.end());
    return cntSSC // return scc;
}