class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int m = 0;
        int n = col-1;

        while((m>=0 && m < row) && (n>=0 && n<col)){
            
            int x1,y1;
            int x2,y2;

            x1 = m;
            y1 = n;
            x2 = m;
            y2 = n;

            while((x1>=0 & x1<row) && (y1>=0 && y1 <col) && (x2 >=0 && x2<row) && (y2>=0 && y2<col)){
                swap(matrix[x1][y1], matrix[x2][y2]);

                y1--;
                x2++;
            }
            
            //Now reverse logic
            int fixed_col = n;
            int i = 0;
            int j = matrix.size()-1;
            while(i<j){
                swap(matrix[i][fixed_col], matrix[j][fixed_col]);
                i++;
                j--;
            }
            
            m++;
            n--;
        }
    }
};
