class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int low =0;
        int high = n-1;
        
        int max_width = (high - low ) * (min(height[low],height[high]));

        while(low < high){
            if(height[low] < height[high]){
                //move the left pointer until it finds the greater height
                int  temp = height[low];
                while(low<high && height[low] <= temp){
                    low++;
                }
            }
            else{
                int temp = height[high];
                while(low<high && height[high] <= temp){
                    high--;
                }
            }
            max_width = max(max_width , (high-low)*(min(height[low],height[high])));
        }
        return max_width;
    }
};
