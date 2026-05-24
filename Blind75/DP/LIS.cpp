//Memoization 
class Solution {
public:

    vector<int> arr;
    int solve(int curr, int prev, vector<vector<int>>& dp){
        if(curr == arr.size()){
            return 0;
        }
        if(prev!=-1 && dp[curr][prev]!=-1){
            return dp[curr][prev];
        }
        //take
        int take = 0;

        if(prev == -1|| arr[curr] > arr[prev]){
            take = 1 + solve(curr+1, curr,dp);
        }

        //skip 
        int skip = solve(curr+1, prev, dp);

        return prev!=-1 ? dp[curr][prev] = max(take, skip) : max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        arr = nums;
        return solve(0,-1,dp);
    }
};

//Lower bound approach
class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            auto it = lower_bound(res.begin(), res.end(), arr[i]);
            if(it == res.end()) {
                res.push_back(arr[i]);
            }
            else{
                *it = arr[i];
            }
        }
        
        return res.size();
    }
};
