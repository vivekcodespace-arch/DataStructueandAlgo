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

//BFS approch Kahn's algorithm

class Solution {
public:
    //BFS Approach using kahn's algo
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        unordered_map<int, vector<int>> mp;

        for(auto& x: prerequisites){
            int u = x[1];
            int v = x[0];
            inDegree[v]+=1;
            mp[u].push_back(v);
        }


        queue<int> q;

        //jitne bhi 0 h unko q me daalo
        for(int i=0;i<numCourses;i++){
            if(!inDegree[i]){
                q.push(i);
            }
        }

        int nodes = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            nodes+=1;
            for(auto& v: mp[front]){
                inDegree[v]-=1;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }

        if(nodes == numCourses){
            return true;
        }

        return false;

    }
};
