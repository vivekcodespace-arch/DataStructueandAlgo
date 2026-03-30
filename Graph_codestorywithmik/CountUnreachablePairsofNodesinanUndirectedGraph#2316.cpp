class Solution {
public: 
    int counter = 0;
    void dfs(int u, vector<bool>& visited, unordered_map<int,vector<int>>& mp){
        visited[u] = true;
        counter++;
        for(auto& v:mp[u]){
            if(!visited[v]){
                dfs(v,visited, mp);
            }
        }

    }
    long long findpairs(vector<int>& nodes){
        int n = nodes.size();
        long long sum = 0;
        vector<int> backSum(nodes);
        for(int i= n-2;i>=0;i--){
            backSum[i] = backSum[i] + backSum[i+1];
        }

        for(int i=0;i<n-1;i++){
            sum = sum + ((long long)nodes[i] * backSum[i+1]);
        }

        return sum;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<int> nodes;
        unordered_map<int, vector<int>> mp;
        for(auto& x: edges){
            int u = x[0];
            int v = x[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            counter = 0;
            if(!visited[i]){
                dfs(i,visited, mp);
                nodes.push_back(counter);
            }
        }


        return findpairs(nodes);
    }
};
