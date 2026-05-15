class Solution {
public:
    int t[201][20001];
    int t_sum = 0;
    bool solve(int i, int csum, vector<int>& nums){
        if(i >= nums.size()) return t[i][csum] =  false;
        if(t[i][csum]!=-1) return t[i][csum];
        int rem_sum = t_sum - csum;

        if(rem_sum < 0) return t[i][csum] = false;
        if(rem_sum == csum) return t[i][csum] = true;
        bool take= false;
        bool skip = false;

        take = solve(i+1, csum + nums[i], nums);

        skip = solve(i+1, csum , nums);

        return t[i][csum] = take || skip;

        
    }
    bool canPartition(vector<int>& nums) {
        //calculate the total sum and then apply take skip pattern
       
        for(int i=0;i<201;i++){
            for(int j =0;j<20001;j++){
                t[i][j] = -1;
            }
        }
        for(auto& x: nums){
            t_sum += x;
        }
        cout<<t_sum;
        return solve(0 ,0, nums);
    }
};
