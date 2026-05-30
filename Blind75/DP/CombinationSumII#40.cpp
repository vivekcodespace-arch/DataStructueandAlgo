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


//2nd backtracking sol
class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void solve(int idx,int totalLeft, int k, int n){
        if(totalLeft == 0 && temp.size() == k) {
            result.push_back(temp);
            return;
        }
        if(totalLeft < 0) return;
        
        if(idx >9) return;

        for(int i=idx;i<10;i++){
            
            temp.push_back(i);
            solve(i+1,totalLeft - i,  k , n);
            temp.pop_back();

        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(1,n, k , n);
        return result;
    }
};
