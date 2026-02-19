class Solution {
public:
    // Brute force approach
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int temp = nums[i] + nums[j] + nums[k];
                    if (temp == 0) {
                        vector<int> v{nums[i], nums[j], nums[k]};
                        sort(v.begin(), v.end());
                        st.insert(v);
                    }
                }
            }
        }
        vector<vector<int>> vec(st.begin(), st.end());
        return vec;
    }
};



