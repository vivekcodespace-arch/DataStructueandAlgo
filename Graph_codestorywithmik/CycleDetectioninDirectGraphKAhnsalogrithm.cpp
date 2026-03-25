class Solution {
  public:
  
  
    bool checkCycleDFS(int u, vector<bool>& visited, vector<bool>& inRecursion, unordered_map<int,vector<int>>& mp){
        visited[u] = true;
        inRecursion[u]  = true;
        
        
        for(auto& v: mp[u]){
            if(!visited[v] && checkCycleDFS(v, visited, inRecursion,mp)){
                return true;
            }
	    //This is else if is optional becuase if that node is visited that it must would have found the cycle previouslt and returned the result.. but it didn't it means that there is not point  in traversing that node again because it will not give any cycle.
            else if(visited[v] && inRecursion[v] == false ){
                continue;
                
            }    
            else if(inRecursion[v]) return true;
            
        }
        
        
        inRecursion[u]  = false;
        
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<bool> visited(V,false);
        vector<bool> inRecursion(V,false);
        
        
        unordered_map<int,vector<int>> mp;
        
        for(auto& x: edges){
            int u = x[0];
            int v = x[1];
            
            mp[u].push_back(v);
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i] && checkCycleDFS(i, visited, inRecursion, mp)){
                return true;
            }
        }
        return false;
    }
};
