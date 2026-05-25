class Solution {
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left{nums[0]};
        int i = 1;

        for (; i < n; i++)
        {
            if (abs(nums[i] - nums[i - 1]) == 1)
            {
                left.push_back(nums[i]);
            }
            else
            {
                break;
            }
        }
        // cout << "The value of i is->" << i << endl;
        vector<int> right;
        if (i < n)
            right.push_back(nums[i]);

        for (int j = i + 1; j < n; j++)
        {
            if (abs(nums[j] - nums[j - 1]) == 1)
            {
                right.push_back(nums[j]);
            }
            else
            {
                return -1;
            }
        }
        // // print right and left numsay
        // cout << "Left array is being printed->";
        // for (auto &x : left)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        // cout << "Right array is being printed->";
        // for (auto &x : right)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;

        if (left.size() == n)
        {
            if (left[0] == 0)
            {
                // cout << "No shift needed";
                return 0;
            }
        }

        bool increasing = false;
        bool decreasing = false;
        
        if(left.size() > 1){
            if(left[1] > left[0]){
                increasing  = true;
            }
            else{
                decreasing = true;
            }
        }
        if(right.size() > 1){
            if(right[1] > right[0]){
                increasing  = true;
            }
            else{
                decreasing = true;
            }
        }
        if(increasing && decreasing){
            
            return -1;
        } 
        if(increasing){
            return min(left.size(), right.size() + 2);
        }
        if(decreasing) {
            return min(left.size() + 1, right.size() + 1);
        }
        
        return -1;
    }

};
