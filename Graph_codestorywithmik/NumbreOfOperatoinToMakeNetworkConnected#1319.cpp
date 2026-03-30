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
//DSU solution

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i, vector<int>& parent){
        if(parent[i] == i) return i;

        return parent[i] = find(parent[i], parent);
    }
    bool Union(int x, int y, vector<int>& parent, vector<int>& rank){
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if(x_parent != y_parent){

            if(rank[x_parent] > rank[y_parent]){
                parent[y_parent] = x_parent;
            }
            else if(rank[x_parent] < rank[y_parent]){
                parent[x_parent] = y_parent;
            }
            else{
                parent[x_parent] = y_parent;
                rank[y_parent]+=1;
            }
            return true;
        }

        return false;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n-1) return -1;

        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        int x = n-1;
        for(auto& connection: connections){
            int u = connection[0];
            int v = connection[1];
            if(Union(u, v, parent, rank)){
                x--;
            }
        }
        return x;

    }
};
