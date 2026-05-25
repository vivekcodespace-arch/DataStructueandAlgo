class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int no = nums[0];
        int n = nums.size();
        int cnt = 0;
        int i = 0;
        int idx = 0;
        while(i<n){
            if(nums[i] == no){
                cnt++;
            }
            if(nums[i] != no){
                cnt = 1;
                no = nums[i];
            }
            if(cnt <= k){
                nums[idx] = no;
                idx++;
            }
            i++;
        }
        nums.erase(nums.begin()+idx, nums.end());
        return nums;
    }
};
