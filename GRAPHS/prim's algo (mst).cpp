// Function to find sum of weights of edges of the Minimum Spanning Tree.
// works only for UNDIRECTED graphs as ALL NODE MUST BE REACHABLE FROM EVERY NODE

int spanningTree(int V, vector<vector<int>> adj[]) {
    
    int sum = 0;
    vector<vector<int>> mstEdges;

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pint,int>>>> pq;

    pq.push({0,{0,-1}});
    
    vector<bool> vis(V,false);
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();
        if(vis[node]) continue;
        
        vis[node] = true;
        
        if(parent != -1){
            sum += dist;
            // mstEdges.push_back(vector<int>{parent,node,dist});
        }
        
        for(auto& val: adj[node]){
            int next = val[0];
            int cost = val[1];
            
            if(!vis[next]){
                pq.push({cost,{next,node}});
            }
        }
    }
    
    return sum; // or mstEdges;
}