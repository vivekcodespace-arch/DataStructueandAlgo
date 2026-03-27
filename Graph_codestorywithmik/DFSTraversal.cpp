//DFS traversal

class Solution {
  public:
    void traverse(vector<vector<int>>& adj , int u , vector<bool>& visited,vector<int>& result){
        if(visited[u]) return ;
        visited[u] = true;
        result.push_back(u);
        for(int &v:adj[u]){
            if(!visited[v]){
                traverse(adj,v,visited,result);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int edges = adj.size();
        vector<int> result;
        vector<bool> visited(edges,false);
        traverse(adj,0,visited,result);
        return result;
        
    }
};
