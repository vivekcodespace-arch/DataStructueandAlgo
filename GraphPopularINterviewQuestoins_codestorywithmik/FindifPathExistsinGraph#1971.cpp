//Problme link: https://leetcode.com/problems/find-if-path-exists-in-graph/


class Solution {
public:
    bool dfs(int u, int dest, unordered_map<int, vector<int>> &mp, vector<bool>& visited)
    {
        visited[u] = true;
        if(u == dest) return true;
        for(auto& v : mp[u]){
            if(!visited[v]&& dfs(v, dest, mp, visited)){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //let's build the adjacency list
        unordered_map<int, vector<int>> mp;
        vector<bool> visited(n, false);
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        return dfs(source, destination, mp, visited);
    }
};
