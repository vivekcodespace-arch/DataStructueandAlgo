//This question is an extensio of the two sum problem but with a change that.
//it should return the maximum two sum less than k
int twoSumK(vector<int> &nums, int k)
{
    vector<int> res;
    // brute force approach
    int max_res = INT_MIN;

    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] < k)
            {
                max_res = max(nums[i] + nums[j], max_res);
                cout << nums[i] << " " << nums[j] << "->" << nums[i] + nums[j] << endl;
            }
        }
    }
    return max_res;
}
