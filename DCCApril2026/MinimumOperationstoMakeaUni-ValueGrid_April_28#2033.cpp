class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        //now the main task is to find which element will be x equal to 
        
        vector<int> oned_grid;
        int init_modulo = grid[0][0] % x;
        
        for(auto& u: grid){
            for(auto& v: u){
                oned_grid.push_back(v);
                if(v%x != init_modulo) return -1;
            }
        }
        int length = oned_grid.size();
        nth_element(oned_grid.begin(),oned_grid.begin()+ length/2,oned_grid.end());
        //What does this function does
        //it ensures that the value at the left of length/2 is less that it 
        //and value after the index lenght/2 is greater
        int req = oned_grid[length/2];
        int cnt = 0;
        for(auto& val: oned_grid){
            int temp = abs(req - val);
            cnt += (temp / x);
        }
        return cnt;

    }
};
