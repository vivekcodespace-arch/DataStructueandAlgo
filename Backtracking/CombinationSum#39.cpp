class Solution {
public:
    vector<vector<int>> result;
    int n;
    vector<int> temp;
    vector<int> arr;
    void solve(int idx,int sum,int target){
        if(sum == target){
            result.push_back(temp);
            return;
        }
        if(sum > target || idx >= n ){
            return ;
        }
        temp.push_back(arr[idx]);
        solve(idx, sum+arr[idx], target);
        temp.pop_back();
        solve(idx+1, sum, target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        arr = candidates;
        solve(0,0,target);
        return result;
    }
};
