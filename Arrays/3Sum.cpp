class Solution {
public:
    // Brute force approach
    //Time Complexity O(n^3)
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

//Better solution TC - (n^2logn)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //inplementing O(n^2logn)
        set<vector<int>> st;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            //implement 2sum
            set<int> hashSet;
            //This block contributes nlogn TC
            for(int j =i+1 ;j<n;j++){
                int rem = -(nums[j] + nums[i]);
                //finding and inserting involves logn time
                if(hashSet.find(rem) != hashSet.end()){
                    vector<int> temp{nums[i],nums[j],rem};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }

        }
         vector<vector<int>> vec(st.begin(),st.end());
        
        return vec;
    }
};

