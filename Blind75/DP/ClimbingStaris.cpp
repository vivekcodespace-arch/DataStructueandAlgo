class Solution {
public:
    int dp[46];
    int solve(int cnt, int n){
        if(cnt > n) return 0;
        if(dp[cnt]!=-1){
            return dp[cnt];
        }
        if(cnt == n) {
            return 1;
        }

        return dp[cnt] = solve(cnt+1,n) + solve(cnt+2,n);
        
    }
    int climbStairs(int n) {
        for(int i=0;i<46;i++){
            dp[i] = -1;
        }
        return solve(0,n);
    }
};
