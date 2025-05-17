bool isCyclic(int V, vector<vector<int>> &edges) {
    queue<int> q;
    vector<int> indegree(V);
    vector<vector<int>> adj(V);
    
    for(auto& val: edges){
        adj[val[0]].push_back(val[1]);
        indegree[val[1]]++;
    }
    
    for(int i = 0; i < V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto& val: adj[node]){
            indegree[val]--;
            if(indegree[val] == 0){
                q.push(val);
            }
        }
    }
    
    if(ans.size() < V) return true;
    
    return false;
}