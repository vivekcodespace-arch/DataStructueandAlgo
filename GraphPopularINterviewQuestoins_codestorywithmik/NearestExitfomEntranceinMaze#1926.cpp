//Prolem link : https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

//T.C same as BFS  O(V+E)
//approach came fiorm that i have to find the shortest distance
class Solution {
public: 
    vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size();
        int col = maze[0].size();

        //now let's apply bfs
        auto isSafe = [&](int x , int y){
            return (x >=0 && x <row ) && (y>=0 && y<col);
        };
        //maze will itself serve as the visited array
        int level = 0;
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty()){

            int N = q.size();

            while(N--){
                pair<int,int> front = q.front();
                int x = front.first;
                int y = front.second;
                q.pop();
                if(!(x == entrance[0] && y == entrance[1])){
                    if(x==0 || x == row-1) return level;
                    if(y ==0 || y == col-1) return level;
                }
                for(auto& dir: directions){
                    int _x = x + dir[0];
                    int _y = y + dir[1];
                    if(isSafe(_x,_y) && maze[_x][_y]!='+'){
                        q.push({_x,_y});
                        maze[_x][_y] = '+';
                    }
                }
            }

            level++;
        }

        return -1;
    }
};
