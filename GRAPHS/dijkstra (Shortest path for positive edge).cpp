// E log(V)
// E = V^2

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

    vector<int> ans(V, INT_MAX);
    // min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
        
    vector<vector<pair<int,int>>> adj(V);
        
    for(auto& val: edges){
        adj[val[0]].push_back({val[1],val[2]});
        adj[val[1]].push_back({val[0],val[2]});
    }
    ans[src] = 0;
        
    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto& val: adj[node]){
            int additional = val.second;
            int ver = val.first;
            
            if(ans[ver] > dist + additional){
                ans[ver] = dist + additional;
                pq.push({ans[ver],ver});
            }
        }
    }
         
    return ans;
}

// same stuff using set 
// we can remove the no longer needed bfs calls but erase takes O(logN)

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

    vector<int> ans(V, INT_MAX);
    set<pair<int,int>> pq;
    pq.insert({0,src});
    
    vector<vector<pair<int,int>>> adj(V);
    
    for(auto& val: edges){
        adj[val[0]].push_back({val[1],val[2]});
        adj[val[1]].push_back({val[0],val[2]});
    }
    ans[src] = 0;
    
    while(!pq.empty()){
        auto it = *(pq.begin());
        int dist = it.first;
        int node = it.second;
        pq.erase(it);
        
        for(auto& val: adj[node]){
            int additional = val.second;
            int ver = val.first;
            
            if(ans[ver] > dist + additional){
                if(ans[ver] != INT_MAX) pq.erase({ans[ver],ver});
                ans[ver] = dist + additional;
                pq.insert({ans[ver],ver});
            }
        }
    }
    
    return ans;
    }