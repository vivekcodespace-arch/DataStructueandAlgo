/* Problem: Minimum Spanning Tree*/

//Problem link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1



class Solution {
  public:
    typedef vector<int> T;
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        //creating a adjacency 
        int sum = 0;
        unordered_map<int, vector<pair<int,int>>> mp; // node -> ( node, wt)
        priority_queue<T, vector<T> , greater<T>> pq;//wt, node, parent
        
        vector<bool> inMST(V,false);
        vector<int> parent(V,-1);
        
        pq.push({0,0,-1});
        
        //popluating the mp
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            mp[u].push_back({v, w});
            mp[v].push_back({u, w});
        }
        //while popping you will populate the vector
        
        while(!pq.empty()){
            auto &top = pq.top();
            int wt = top[0];
            int node = top[1];
            int par = top[2];
            pq.pop();
            if(inMST[node]) continue;
            sum+=wt;
            inMST[node] = true;
            parent[node] = par;
            
            //where we can go from this node
            //sum += wt;
            for(auto& v :  mp[node]){
                int connected_node = v.first;
                int its_wt = v.second;
                
                if(!inMST[connected_node]){
                    parent[connected_node] = node;
                    pq.push({its_wt, connected_node ,node});
                }
            }
            
        }
        return sum;
    }
};
