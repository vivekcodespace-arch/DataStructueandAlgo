//finding minimum spanning tree via kruskal's algorithm

//T.C - O(ElogE)  it is scientifically proved that it takes cosntant time in find and union operation that's why the time complexity is dominated by the sorting which is O(ElogE)
//S.C = for time complexity we can see we have O(V) + O(V) for storing the rank and parent which boils down to O(V)

class Solution {
  public:
  
    // i have to write two thigns union and find
    int find(int i, vector<int> &parent){
        if(parent[i] == i) return i;
        
        return parent[i] = find(parent[i], parent);
    }
    
    bool Union(int x, int y , vector<int>& rank, vector<int>& parent){
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
        
        if(x_parent!=y_parent){
            if(rank[x_parent] > rank[y_parent]){
                parent[y_parent] = x_parent;
            }
            else if(rank[x_parent] < rank[y_parent]){
                parent[x_parent] = y_parent;
            }
            else{
                parent[y_parent] = x_parent;
                rank[x_parent]++;
            }
            
            return true;
        }
        
        return false;
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        //sort in ascending order
        auto comparator = [&](vector<int>&e1, vector<int>&e2){
            return e1[2] < e2[2];  
        };
        sort(begin(edges), end(edges), comparator);
        int total_path = 0;
        vector<int> rank(V,0);
        vector<int> parent;
        for(int i=0;i<V;i++){
            parent.push_back(i);
        }
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            bool response = Union(u,v,rank, parent);
            if(response){
                total_path += wt;
            }
        }
        return total_path;
    }
};
