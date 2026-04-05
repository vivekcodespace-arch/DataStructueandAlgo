/*

Problem: 1631. Path With Minimum Effort
Link :https://leetcode.com/problems/path-with-minimum-effort/

T.C - O(m*n*log(mn))
S.C - O(m*n)
*/

//Approach - Dijkstra algo
class Solution {
public:
    typedef pair<int, pair<int,int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>> directions{{0,-1},{0,1},{-1,0},{1,0}};
        auto isSafe= [&](int x,int y){
            return (x>=0 && x<row) && (y>=0 && y<col);
        };
        priority_queue<P, vector<P> ,greater<P>> pq;
        vector<vector<int>> result(row,(vector<int>(col,INT_MAX)));
        pq.push({0,{0,0}});
        result[0][0] = 0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int max_diff = top.first;
            int node_x = top.second.first;
            int node_y = top.second.second;

            //One more optimization can be done .. as we are maintaing pq we can return 
            //the max_diff when the row , col becomes row-1 and col-1
            if(node_x == row-1 && node_y == col-1) return max_diff;

            for(auto & dir: directions){
                int _x = node_x + dir[0];
                int _y = node_y + dir[1];

                if(isSafe(_x,_y)){
                    int temp = max(max_diff , abs(heights[node_x][node_y]- heights[_x][_y]));
                    if(temp < result[_x][_y]){
                        result[_x][_y] = temp;
                        pq.push({temp,{_x,_y}});
                    }
                }
            }
        }
        return result[row-1][col-1];

    }
};
