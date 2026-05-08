class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftMax(n);
        vector<int> rightMin(n);
        rightMin[n-1] = nums[n-1];
        leftMax[0] = nums[0];

        for(int i=1;i<n;i++){
            leftMax[i] = max(nums[i], leftMax[i-1]);
        }
        //Now i have to calculate the rightMin
        for(int i = n-2;i>=0;i--){
            rightMin[i] = min(rightMin[i+1], nums[i]);
        }

        vector<int> res(n);

        for(int i=n-1;i>=0;i--){

            if(i == n-1 || leftMax[i] <= rightMin[i+1]){
                res[i] = leftMax[i];
            }
            else{
                res[i] = res[i+1];
            }

        }
        return res;
    }
};
