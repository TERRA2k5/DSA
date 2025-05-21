class DisjointSet {
	vector<int> rank, parent, sizes;
public:

	// constructor
	DisjointSet(int n){

		// use one of size or rank
		rank.resize(n+1,0);
		sizes.resize(n+1,1);

		parent.resize(n+1);
		for(int i = 0; i < n+1; i++){
			parent[i] = i;
		}
	}

	int findUparent(int node){
		if(node == parent[node]){
			return node;
		}
		return parent[node] = findUparent(parent[node]);
	}

	// use one of size or rank
	void unionByRank(int u, int v){
		int up_u = findUparent(u);
		int up_v = findUparent(v);

		if(up_u == up_v) return;

		if(rank[up_u] < rank[up_v]){
			parent[up_u] = up_v;
		}
		else if(rank[up_u] > rank[up_v]){
			parent[up_v] = up_u;
		}
		else{
			parent[up_v] = up_u;
			rank[up_u]++;
		}
	}

	// use one of size or rank
	void unionBySize(int u, int v){
		int up_u = findUparent(u);
		int up_v = findUparent(v);

		if(up_u == up_v) return;

		if(sizes[up_u] <= sizes[up_v]){
			parent[up_u] = up_v;
			sizes[up_v] += sizes[up_u];
		}
		else{
			parent[up_v] = up_u;
			sizes[up_u] += sizes[up_v];
		}
	}
};

class Solution {
  public:
  
    int kruskalsMST(int V, vector<vector<int>> &edges) {

        DisjointSet ds(V);
        
        vector<vector<int>> newEdges; // in form of {dist, u, v}
        
        for(auto& val: edges){
            newEdges.push_back(vector<int>{val[2],val[1],val[0]});
        }
        sort(newEdges.begin(),newEdges.end());
        
        vector<vector<int>> edgesMst; // get new MST edges in form {dist, u, v}
        int sum = 0;
        
        for(auto& val: newEdges){
            int cost = val[0];
            int u = val[1];
            int v = val[2];
            
            if(ds.findUparent(u) != ds.findUparent(v)){
                sum += cost;
                edgesMst.push_back(val);
                ds.unionBySize(u,v);
            }
        }
        
        // edgesMst are in form of {dist, u, v}
        return sum; // or edgesMst; 
    }
};