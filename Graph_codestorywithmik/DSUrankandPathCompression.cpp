//DSU path compressio optimizing  using find

int find(int u,vector<int>& parent){
	if(parent[i]==i){
		return i;
	}
	return parent[i] == find(parent[i],parent);
}

//optimizing the union using rank 
void union(int x, int y, vector<int>& parent, vector<int>& rank){
	int x_parent = find(x,parent);
	int y_parent = find(y, parent);

	if(rank[x_parent] > rank[y_parent])
	{
		parent[y_parent] = x_parent;
	}
	else if(rank[x_parent] < rank[y_parent]){
		parent[x_parent] = y_parent;
	}
	else{
		paernt[x_parent] = y_parent;
		rank[y_parent]+=1;
	}
}

