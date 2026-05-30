class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void solve(int i , int totalLeft, vector<int>& candidates, int target){
        // cout<<"hi";
        
        if(totalLeft == 0){
            res.push_back(temp);
            return;
        }
        if(totalLeft  < 0){
            return;
        }
        for(int x = i; x < candidates.size() ; x++){
            if(totalLeft < candidates[i]) break;
            if(x > i && candidates[x] == candidates[x-1]){
                continue;
            }
            temp.push_back(candidates[x]);
            solve(x+1, totalLeft - candidates[x],candidates, target);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),  candidates.end());
        solve(0,target,candidates, target);
        return res;
    }
};
