class Solution {
public:
    //optimized solution using XOR operation 
    // a^a = 0;
    // a^0 = a;
    // (1^2^3^4) ^ (1^2^4) = 3
    int missingNumber(vector<int>& nums) {
        int xr = 0;
        for(int i=1;i<=nums.size();i++){
            xr = xr ^ i; 
        }   
        for(auto& x: nums){
            xr = xr ^ x;
        }
        return xr;
    }
};
