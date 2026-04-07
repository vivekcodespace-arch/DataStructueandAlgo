/*------------------------------------------Floyd Warshall Algorithm-----------------------------------------------*/
/*
	This algorithm is used to find the shortest distance between every pair of vertices in an directed weighted graph.
	
	-> We can also detect -ve cycle via floyd warsahll algorithm.
		How can we detect if we found any weight in the diagonal element of the grid .. because for going from 0->0 it shoudl be 0 only not any interger value
*/


// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int V = dist.size();
        
        for(int via=0; via<V;via++){
            
            for(int row = 0;row<V;row++){
                for(int col = 0;col<V;col++){
                    if(dist[row][via] < 1e8 && dist[via][col] < 1e8) // Why this if we remove this then 1e8-1 is also counted in the minimum weight 
                    dist[row][col] = min(dist[row][col] , dist[row][via] + dist[via][col]);
                }
            }
        }
        
        
    }
};



