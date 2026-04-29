//Normal recursive sol but time limit exceeded
class Solution {
  public:
    int N ;
    int solve(int curr, vector<int>& height){
        if(curr == 0) return 0;
        
        int a = solve(curr - 1, height) + abs(height[curr-1] - height[curr]);
        int b;
        if(curr>1){
        b = solve(curr -2, height) +  abs(height[curr-2] - height[curr]);
        }
        else{
            return a;
        }
        return min(a,b);
        
    }
    int minCost(vector<int>& height) {
        // Code here
        
        N = height.size();
        
        
        return solve(N-1,height);
        
    }
};

//DPsol
class Solution {
  public:
    int N ;
    int t[100001];
    int solve(int curr, vector<int>& height){
        if(curr == 0) return 0;
        
        if(t[curr]!=-1) return t[curr];
        
        int a = solve(curr - 1, height) + abs(height[curr-1] - height[curr]);
        int b = INT_MAX;
        if(curr>1){
            b = solve(curr -2, height) +  abs(height[curr-2] - height[curr]);
        }
        return t[curr] = min(a,b);
        
    }
    int minCost(vector<int>& height) {
        // Code here
        for(int i=0;i<100001;i++){
            t[i] = -1;
        }
        N = height.size();
        
        
        return solve(N-1,height);
        
    }
};

//Bottom up approach without space opti
class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        
        vector<int> dp(n,-1);
        
        dp[0] = 0;
        
        for(int i=1;i<n;i++){
            int fs = dp[i-1] + abs(height[i-1] - height[i]);
            
            int ss = INT_MAX;
            
            if(i > 1){
                ss = dp[i-2] + abs(height[i-2]- height[i]);
            }
            
            dp[i] = min(fs,ss);
        }
        
        return dp[n-1];
    }
};

//Bottom-up approach with space opti

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        
        vector<int> dp(n,-1);
        
        
        int prev1 = 0;
        int prev2 = 0;
        
        for(int i=1;i<n;i++){
            int fs = prev1 + abs(height[i-1] - height[i]);
            
            int ss = INT_MAX;
            
            if(i > 1){
                ss = prev2 + abs(height[i-2]- height[i]);
            }
            int curri;
            curri = min(fs,ss);
            prev2 = prev1;
            prev1 = curri;
        }
        
        return prev1;
    }
};

