//This is was the DFS soliution time complexity O(V+E) 
//Problem link: https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    bool bipartite(int u, int i, vector<int>& colors, unordered_map<int, vector<int>>& mp) {
        colors[u] = i;

        for(auto& v: mp[u]){
            if(colors[v] == colors[u]){
                return false;
            }
            if(colors[v] == -1){
                if(!bipartite(v,1-i,colors,mp)) return false;
            }
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //simple implementation of bipartite graph
        //make the adjacency list 
        unordered_map<int, vector<int>> mp;
        for(auto& edge: dislikes){
            int u = edge[0];
            int v = edge[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<int> colors(n+1,-1);

        for(int i = 1;i<=n;i++){
            if(colors[i] == -1){
                if(!bipartite(i,1,colors,mp))
                {
                    return false;
                }
            }
        }
        return true;
    }
};


//This is was the BFS soliution time complexity O(V+E) 
//Problem link: https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    bool bipartite(int u, int i, vector<int>& colors, unordered_map<int, vector<int>>& mp) {
        colors[u] = i;
        queue<int> q;
        q.push(u);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto & v: mp[front]){
                if(colors[v] == colors[front]){
                    return false;
                }
                if(colors[v] == -1){
                    colors[v] = 1-colors[front];
                    q.push(v);
                }
            }

        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //simple implementation of bipartite graph
        //make the adjacency list 
        unordered_map<int, vector<int>> mp;
        for(auto& edge: dislikes){
            int u = edge[0];
            int v = edge[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<int> colors(n+1,-1);

        for(int i = 1;i<=n;i++){
            if(colors[i] == -1){
                if(!bipartite(i,1,colors,mp))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
