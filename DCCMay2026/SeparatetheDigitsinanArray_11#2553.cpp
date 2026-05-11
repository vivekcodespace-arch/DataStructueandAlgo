class Solution {
public:

    void solve(int n,vector<int>& temp){//This function separete the digits 
        if(n == 0) return ;

        solve(n/10, temp);
        temp.push_back(n%10);

        return ;
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(auto& x: nums){
            vector<int> temp;
            solve(x, temp);

            ans.insert(ans.end(),temp.begin(), temp.end());

        }

        return ans;
    }
};
