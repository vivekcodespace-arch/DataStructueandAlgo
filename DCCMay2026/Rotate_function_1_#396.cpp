class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int res = 0;

        int n = nums.size();

        for(int i=0;i<n;i++){
            res += i * nums[i];
            sum += nums[i];
        }
        
        int max_res = res;
        //iterate from n-2 to 0

        for(int i = n-2; i>=0;i--){

            int temp;

            temp = (sum - nums[i+1])  - ((n-1)* nums[i+1]);
            

            res += temp;

            max_res = max(res, max_res);
        }

        return max_res;
    }
};
