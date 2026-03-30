//bfs and map solution
class Solution {
public:
    void bfs(int u, vector<bool>& visited, unordered_map<int,vector<int>>& mp){
        queue<int> q;
        q.push(u);
        visited[u] = true;


        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto& v: mp[front]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n-1) return -1;
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> mp;

        for(auto& connection: connections){
            int u = connection[0];
            int v = connection[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int group=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(i,visited, mp);
                group++;
            }
        }
        return group-1;
    }
};
