//Problem link: https://leetcode.com/problems/keys-and-rooms/
//Problem algo : basic dfs and bfs 
//T.c  same as dfs which is O(V+E)


//dfs solution 
class Solution {
public:
    void dfs(int u, vector<bool>& visited,unordered_map<int, vector<int>>& mp){
        visited[u] = true;

        for(auto& v: mp[u]){
            if(!visited[v]){
                dfs(v, visited, mp);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //simply we can crate an adjaency where index is of the room is the first in the map and the kay it contains is it's the value of the index of the index of the map
        int n = rooms.size();
        unordered_map<int, vector<int>> mp;
        for(int u=0 ; u<n ;u++){
            for(auto& v : rooms[u]){
                mp[u].push_back(v);
            }
        }

        vector<bool> visited(n, false);

        dfs(0, visited, mp);

        //check if all the rooms are visited if visited return true otherwise fales;
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};


//bfs solution
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //We can also implement it via bfs

        //first let's create an adjacency list
        unordered_map<int, vector<int>> mp;
        int n = rooms.size();
        for(int u=0;u<n;u++){
            
            for(auto& v: rooms[u]){
                mp[u].push_back(v);
            }
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto& v: mp[front]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }

        //check if all the rooms are visited
        for(auto v: visited){
            if(!v) return false;
        }
        return true;
    }

};
