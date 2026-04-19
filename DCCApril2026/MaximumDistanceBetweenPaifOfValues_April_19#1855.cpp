class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int max_result = 0;
        while(i< nums1.size() && j<nums2.size()){

            while(j<nums2.size() && nums1[i]<=nums2[j]){
                max_result = max(max_result, j-i);
                j++;
            }

            while((i < nums1.size() && j <nums2.size()) && nums1[i] > nums2[j]){
                i++;
            }
        }
        return max_result;
    }
};
