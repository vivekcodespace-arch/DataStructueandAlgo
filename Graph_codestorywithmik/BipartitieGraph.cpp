
//DFS solution
class Solution {
  public:
  
  
    bool solve(int u,int i, vector<int> &colors, unordered_map<int,vector<int>>& mp){
        colors[u] =i;
        
        for(auto& v: mp[u]){
            if(colors[v] == i){
                return false;
            }
            if(colors[v] == -1){
                int change_color = 1-i;
                if(!solve(v,change_color, colors,mp)){
                    return false;
                }
            }
        }
        
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        unordered_map<int,vector<int>> mp;
        vector<int> colors(V,-1);
        for(auto& x: edges){
            int u =x[0];
            int v = x[1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        for(int i=0;i<V;i++){
            if(colors[i]==-1 && solve(i,1,colors,mp)==false){
                return false;
            }
        }
        return true;
        
    }
};
//BFS solution
class Solution {
  public:
  
  
    bool BFS(int current_node, int current_color, vector<int>& colors, unordered_map<int,vector<int>> &mp){
        queue<int> q;
        q.push(current_node);
        colors[current_node] = current_color;
        
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto& v:mp[u]){
                if(colors[v] == colors[u]){
                    return false;
                }
                else if(colors[v] == -1){
                    
                    colors[v] = 1 - colors[u];
                    q.push(v);
                }
            }
        }
        
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        
        unordered_map<int,vector<int>> mp;
        vector<int> colors(V,-1);
        for(auto& x: edges){
            int u =x[0];
            int v = x[1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        for(int i=0;i<V;i++){
            if(colors[i]==-1 && BFS(i,1,colors,mp)==false){
                return false;
            }
        }
        return true;
        
    }
};
