//Problem link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
//Problem :  947 leetcode
//Simple implementation of depth first search we can also implement it via BFS

//Simple DFS solution
//T.C is not same as DFS becuase while creatin of the adjacency list , you traversed approx. O(n^2) time optimum solution can be made using union-find (DSU)
//Space is used in making the adjacency list which is again O(V+E) + O(V) for storing whether the node is visited or not

class Solution {
public:
    int dfs(int u, unordered_map<int, vector<int>>&mp, vector<bool>& visited){
        visited[u] = true;
        int count = 1;

        for(auto &v: mp[u]){
            if(!visited[v]){
                count+=dfs(v,mp, visited);
            }
        }
        return count;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n,false);
        unordered_map<int, vector<int>> mp;
        //Create the adjacency list
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        int max_stone_removed = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                // count = 0;
                int temp = dfs(i,mp, visited);
                temp--;
                max_stone_removed += temp;
            }
        }
        return max_stone_removed;
    }
};
