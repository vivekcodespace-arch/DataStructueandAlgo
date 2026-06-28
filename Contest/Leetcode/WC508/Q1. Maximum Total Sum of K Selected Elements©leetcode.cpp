#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long sum =0;

        for(int i=0;i<k;i++){
            if(mul > 1){
                sum = sum  + (nums[i] * (long long)mul);
                mul--;
            }
            else{
                sum += nums[i];
            }
        }
        return sum;
    }
};

//Driver code 