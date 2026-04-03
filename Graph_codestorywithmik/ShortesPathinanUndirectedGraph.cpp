class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        int src = 1;
        vector<int> result(n+1,INT_MAX);
        result[src] = 0;
        vector<int> parent(n+1);
        set<pair<int,int>> st; // node, distance
        st.insert({1,0}); 
        
        //constructing the adjaceny list
        unordered_map<int, vector<pair<int,int>> > mp;
        
        for(auto &x: edges){
            int u = x[0];
            int v = x[1];
            int w = x[2];
            
            mp[u].push_back({v, w});
            mp[v].push_back({u, w});
            
        }
        for(int i=0;i < n+1;i++){
            parent[i] = i;
        }
        
        
        while(!st.empty()){
            
            auto &it = *st.begin();
            int node = it.first;
            int distance = it.second;
            st.erase(it);
            
            for(auto& v : mp[node]){
                int new_node = v.first;
                int new_dist = v.second;
                
                if(distance + new_dist < result[new_node]){
                    
                    if(result[new_node]!=INT_MAX){
                        st.erase({new_node,result[new_node]});
                    }
                    parent[new_node] = node;
                    result[new_node] = distance + new_dist;
                    st.insert({new_node, distance + new_dist});
                }
            }
            
        }
        
       
        if(result[n] == INT_MAX) return {-1};
        vector<int> ans;
        
        int x = n;
        
        while(parent[x] != x){
            // cout<<x<<" ";
            ans.push_back(x);
            x = parent[x];    
            
        }
        // cout<<x<<" ";
        ans.push_back(x);
        ans.push_back(result[n]);
        
        reverse(ans.begin(),ans.end());
        
        return  ans;
        
    }
};
