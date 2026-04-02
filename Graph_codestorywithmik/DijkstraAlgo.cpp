class Solution {
  public:
  
  
    
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int, vector<pair<int,int>>> mp;
        for(auto &x : edges){
            int u = x[0];
            int v = x[1];
            int w = x[2];
            
            mp[u].push_back({v,w});//node, weight
            mp[v].push_back({u,w});
        }
        
        vector<int> result(V,INT_MAX);
        result[src] = 0;
        pq.push({0,src}); // distance ,node
        
        while(!pq.empty()){
            // cout<<"hellow";
            pair<int,int> temp = pq.top();
            pq.pop();
            int distance = temp.first;
            int node = temp.second;
            
            for(auto& v: mp[node]){
                int new_node = v.first;
                int wt = v.second;
                // cout<<"b";
                if(distance+wt < result[new_node]){
                    result[new_node] = distance + wt;
                    pq.push({distance+wt, new_node});
                }
            }
        }
        
        return result;
        
    }
};
