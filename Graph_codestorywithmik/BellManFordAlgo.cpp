//Bellman Ford algorithm .. where does the dijkstra fails
//Consider this example give edges and weitghts [0,1,-1] 
//There is a undirected graph with a edges between 0 and 1 node with a weight of -1
//try to implement Dijkstra in it . you will find why bellman ford algo exists..


// User function Template for C++


class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> result(V,1e8);
        result[src] = 0;
        
        for(int i=0;i<V-1;i++){
            
            for(auto& edge: edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(result[u]!=1e8 && result[u]+w < result[v]){
                    result[v] = result[u] + w;
                }
            }
        }
        
        //check if further relaxation can be done
        for(auto& edge: edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(result[u]!=1e8 && result[u]+w < result[v]){
                    return {-1};
                }
            }
        
        
        return result;
    }
};

