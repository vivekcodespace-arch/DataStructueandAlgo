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
