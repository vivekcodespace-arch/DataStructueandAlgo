//Problem link: https://leetcode.com/problems/keys-and-rooms/
//Problem algo : basic dfs and bfs 
//T.c  same as dfs which is O(V+E)


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
