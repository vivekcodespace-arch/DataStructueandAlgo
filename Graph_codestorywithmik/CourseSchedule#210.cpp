//Using BFS traversal Kahn's algorithm
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans; // used to store the answer
        unordered_map<int, vector<int>> mp;
        vector<int> inDegree(numCourses, 0);

        for (auto& x : prerequisites) {
            int u = x[1];
            int v = x[0];
            inDegree[v] += 1;
            mp[u].push_back(v);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto& v : mp[front]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (ans.size() == numCourses) {
            return ans;
        }
        return {};
    }
};

//Using DFS traversal and topological sorting via DFS traversal
class Solution {
public:
    stack<int> st; // used to store the answer
    bool isCycleDFS(int u, unordered_map<int,vector<int>>& mp, vector<bool>& visited, vector<bool>& inRecursion){
        
        visited[u]  = true;
        inRecursion[u] = true;
        for(auto& v: mp[u]){
            if(!visited[v]){
                if(isCycleDFS(v,mp,visited,inRecursion)){
                    return true;
                }
            }
            if(inRecursion[v] == true){
                return true;
            }
        }
        st.push(u);
        inRecursion[u]  = false;
        return false;
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        for (auto& x : prerequisites) {
            int u = x[1];
            int v = x[0];
            mp[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && isCycleDFS(i,mp,visited,inRecursion)){
                return {};
            }
        }
        vector<int> ans;
        
        while(!st.empty()){
            int top = st.top();
            st.pop();
            ans.push_back(top);
        }

        return ans;
    }
};

