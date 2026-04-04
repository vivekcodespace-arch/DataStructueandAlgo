class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //Bfs traversal solution 
        if(grid[0][0] == 1) return -1;
        vector<vector<int>> direction{{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{-1,1},{1,1},{1,-1}};
        int n = grid.size();
        int level = 0;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        auto safeCheck = [&](int x,int y){
            return (x>=0 && x<n) && (y>=0 && y<n);
        };
        while(!q.empty()){

            int N = q.size();

            while(N--){
                pair<int,int> front = q.front();
                q.pop();
                int x = front.first;
                int y = front.second;
                if(x == n-1 && y == n-1) {
                    return level+1;
                }
                for(auto& dir: direction){
                    int _x = x + dir[0];
                    int _y = y + dir[1];

                    if(safeCheck(_x,_y) && grid[_x][_y] == 0){
                        grid[_x][_y] = 1;
                        q.push({_x,_y});
                    }

                }

            }
            level++;
        }

        return -1;
    }
};
//Solve using  Dijkstra algorithm

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> directions{{-1, -1}, {-1, 0}, {-1, 1},
                                       {0, -1},  {0, 0},  {0, 1},
                                       {1, -1},  {1, 0},  {1, 1}};
        vector<vector<int>> result(grid.size(),
                                   vector<int>(grid.size(), INT_MAX));
        if(grid[0][0] == 1 || grid[n-1][n-1]!=0) return -1;
        result[0][0] = 0;
        auto isSafe = [&](int x, int y) {
            return (x >= 0 && x < grid.size()) && (y >= 0 && y < grid.size());
        };
        priority_queue<P, vector<P>, greater<P>> pq; // distance , node
        
    

        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int distance = top.first;
            int node_x = top.second.first;
            int node_y = top.second.second;

            for (auto& dir : directions) {
                int _x = node_x + dir[0];
                int _y = node_y + dir[1];
                int wt = 1 + distance;
                if ((isSafe(_x, _y) && grid[_x][_y]!=1 ) && wt < result[_x][_y]) {
                    result[_x][_y] = wt;
                    pq.push({wt, {_x, _y}});
                }
            }
        }

        if(result[n-1][n-1] == INT_MAX) return -1;
        return result[grid.size() - 1][grid.size() - 1]+1;
    }
};
