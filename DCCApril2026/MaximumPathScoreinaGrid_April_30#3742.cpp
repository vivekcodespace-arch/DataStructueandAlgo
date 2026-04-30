//Recursive sol

class Solution {
public:
    int m;//rows
    int n;//cols
    int solve(vector<vector<int>>& grid, int k , int i, int j,int cost){
        if(i >=m || j>=n) return INT_MIN;
        
        int newcost = cost + (grid[i][j] > 0 ? 1 : 0);

        if(newcost > k ) return INT_MIN;

        if(i == m-1 && j ==n-1){
            return grid[i][j];
        }

        int right = solve(grid, k, i ,j+1, newcost);
        int down = solve(grid, k, i+1, j, newcost);

        int bestresult = max(right,down);
        if(bestresult == INT_MIN) return INT_MIN;

        return bestresult + grid[i][j];

    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int res = solve(grid, k, 0,0,0);
        return res == INT_MIN ? -1 : res;
    }
};

//Dp sol
class Solution {
public:
    int m;//rows
    int n;//cols
    
    int solve(vector<vector<int>>& grid, int k , int i, int j,int cost,vector<vector<vector<int>>> &t){
        if(i >=m || j>=n) return INT_MIN;
        
        if(t[i][j][cost]!=-1) return t[i][j][cost];
        
        int newcost = cost + (grid[i][j] > 0 ? 1 : 0);

        if(newcost > k ) return INT_MIN;


        if(i == m-1 && j ==n-1){
            return t[i][j][cost] = grid[i][j];
        }

        int right = solve(grid, k, i ,j+1, newcost,t);
        int down = solve(grid, k, i+1, j, newcost,t);

        int bestresult = max(right,down);
        if(bestresult == INT_MIN) return t[i][j][cost] = INT_MIN;

        return t[i][j][cost] = bestresult + grid[i][j];

    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> t(m+1, vector<vector<int>>(n+1, vector<int>(k+1,-1)));
        int res = solve(grid, k, 0,0,0,t);
        return res == INT_MIN ? -1 : res;
    }
};


//Backtracking sol
class Solution {
public:
    
    //Bottom-up approach
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> t(m+1, vector<vector<int>>(n+1, vector<int>(k+1,-1)));

        for(int i=m-1;i>=0;i--){

            for(int j = n-1;j>=0;j--){

                for(int cost = k;cost>=0;cost--){
                    int newcost = cost + (grid[i][j] > 0 ? 1:0);

                    if(newcost > k) continue;

                    if(i == m-1 && j == n-1){
                        t[i][j][cost] = grid[i][j];
                        continue;
                    }
                    int right = -1;
                    int down = -1;
                    if(j+1 < n) right = t[i][j+1][newcost];
                    if(i+1 < m) down = t[i+1][j][newcost];
                    
                    int bestres = max(right, down);
                    if(bestres!=-1){
                        t[i][j][cost] = bestres + grid[i][j];
                    }
                }
            }
        }

        return t[0][0][0];
    }
};
