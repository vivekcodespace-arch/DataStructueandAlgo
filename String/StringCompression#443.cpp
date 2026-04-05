/*
Problem: String Compression
Link: https://leetcode.com/problems/string-compression/
*/
/*-------------------------------------------------Solution------------------------------------------------*/
//T.C - O(n)
class Solution {
public:
    int compress(vector<char>& chars) {
        
        int curr_index = 0;
        int index =0 ;
        int i=0;
        int n = chars.size();
        while(i < n ){

            int cnt =0 ;
            while(i<n && chars[curr_index] == chars[i]){
                cnt++;
                i++;
            }
            //Assigning the chars
            chars[index] = chars[curr_index];
            index++;
            if(cnt!=1){
                string temp = to_string(cnt);
                for(auto&c : temp){
                    chars[index] =c ;
                    index++;
                }
            }
            curr_index = i;
        }

        return index;
    }
};
