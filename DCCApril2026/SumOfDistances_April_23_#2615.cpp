class Solution {
public:
    //T.C - O(n) + (n) = O(n)
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> sum;
        vector<long long> ans;
        int n = nums.size();
        //left se traverse kr rhe h
        for(int i=0;i<n;i++){
            long long temp = 0;
            temp = i * freq[nums[i]] - (sum[nums[i]]);

            freq[nums[i]]++;
            sum[nums[i]]+= i;
            ans.push_back(temp);
        }  
        freq.clear();
        sum.clear();
        //right se traversal krenge and same thing will be applied
        for(int i = n-1;i>=0;i--){
            long long temp = 0;
            temp = sum[nums[i]] - (i * freq[nums[i]]);
            freq[nums[i]]++;
            sum[nums[i]]+=i;
            ans[i]+=temp;
        }
        return ans;
    }
};
