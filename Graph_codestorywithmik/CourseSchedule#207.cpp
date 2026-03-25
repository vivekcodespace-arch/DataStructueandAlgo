class Solution {
public:
    //dfs approach inRecursion
    bool isCycleDFS(int u, vector<bool>& visited, unordered_map<int, vector<int>>& mp, vector<bool>& inRecursion){
        visited[u] = true;
        inRecursion[u] = true;
        for(auto& v: mp[u]){
            if(!visited[v]){
                if(isCycleDFS(v, visited, mp, inRecursion)){
                    return true;
                }
            }
            if(inRecursion[v] == true){
                return true;
            }
        }
        inRecursion[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<bool> visited(V,false);
        unordered_map<int, vector<int>> mp;
        vector<bool> inRecursion(V,false);

        for(auto& x: prerequisites){
            int v = x[0];
            int u = x[1];

            mp[u].push_back(v);
        }
        for(int i=0;i<V;i++){
            if(!visited[i] && isCycleDFS(i, visited, mp,inRecursion)){
                return false;

            }
        }
        return true;

    }
};
