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

