class Solution {
public:
    //This run in O(n) times
    int findOnes(int n){
        int count = 0;
        int num = n;
        while(n!=0){
            if(n & 1){
                count++;
            }
            n = n>>1;
        }
        return count;

    }
    vector<int> countBits(int n) {
        //brute force approach to find the no. of ones
        vector<int> ans(n+1);
        //This loop runs for n times so TC = O(n^2)
        for(int i=0;i<=n;i++){
            ans[i] = findOnes(i);
        }
        return ans;
    }
};
//More optimized solution works in linear time
//On the face that for even integer no. of setbits is same as n>>1
//And for odd integers it is n>>1 + 1
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};
