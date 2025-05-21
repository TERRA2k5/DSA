#include <bits/stdc++.h>
using namespace std;


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

int main(){

	DisjointSet ds(7);
	// ds.unionByRank(1,2);
	// ds.unionByRank(3,2);
	// ds.unionByRank(4,5);
	// ds.unionByRank(6,5);
	// ds.unionByRank(7,6);

	ds.unionBySize(1,2);
	ds.unionBySize(3,2);
	ds.unionBySize(4,5);
	ds.unionBySize(6,5);
	ds.unionBySize(7,6);

	(ds.findUparent(3) == ds.findUparent(6)) ? cout << "Same\n" : cout << "Different\n";

	ds.unionBySize(3,7);
	// ds.unionByRank(3,7);

	(ds.findUparent(3) == ds.findUparent(6)) ? cout << "Same\n" : cout << "Different\n";

	return 0;
}	