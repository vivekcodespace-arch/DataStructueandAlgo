//The most brute force solution , uses an extra space of the size of the nodes


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


//More better approach using dfs traversal and without using any extra space

class Solution {
public: 
    int count = 0;
    int dfs(int u, vector<bool>& visited, unordered_map<int,vector<int>>& mp){
        visited[u] = true;
        int sum = 1;
        for(auto& v:mp[u]){
            if(!visited[v]){
                sum += dfs(v,visited, mp);
            }
        }
        return sum;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> nodes;
        unordered_map<int, vector<int>> mp;
        vector<bool> visited(n, false);
        for(auto& x: edges){
            int u = x[0];
            int v = x[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        int total_nodes = n;
        long long result = 0;
        
        for(int i=0;i<n;i++){
            
            if(!visited[i]){
                int temp = dfs(i,visited, mp);
               
                result = result + ((long long)temp * (total_nodes-temp));

                total_nodes = total_nodes-temp;
            }
        }


        return result;
    }
};


//Same logic but now with a bfs iteration 


class Solution {
public: 

    //now i have to do the same counting via bfs traversal 
    
    int bfs(int u, vector<bool>& visited, unordered_map<int,vector<int>>& mp){
        int count = 0;
        queue<int> q;
        q.push(u);
        count++;
        visited[u] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto& v: mp[front]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                    count++;
                }
            }
        }
        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> nodes;
        unordered_map<int, vector<int>> mp;
        vector<bool> visited(n, false);
        for(auto& x: edges){
            int u = x[0];
            int v = x[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        int total_nodes = n;
        long long result = 0;
        
        for(int i=0;i<n;i++){
            
            if(!visited[i]){
                int temp = bfs(i,visited, mp);
               
                result = result + ((long long)temp * (total_nodes-temp));

                total_nodes = total_nodes-temp;
            }
        }


        return result;
    }
};


//Solution using disjoint set union

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i, vector<int>& parent){
        if(parent[i] == i) return i;

        return parent[i] = find(parent[i], parent);
    }
    void Union(int x, int y, vector<int>& parent, vector<int>& rank){
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        //now i have to implement it via DSU
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        //firstly iterate in the edges and then union them
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];

            Union(u,v,parent,rank);
        }

        //then after apply the find operation and make a map
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            int temp = find(i,parent);
            mp[temp]+=1;
        }
        int total_nodes = n;
        long long result = 0;
        for(auto& x:mp)
        {
            int temp = x.second;
            result += (long long)temp * (total_nodes-temp);
            total_nodes = total_nodes - temp;
        }

        return result;

    }
};
