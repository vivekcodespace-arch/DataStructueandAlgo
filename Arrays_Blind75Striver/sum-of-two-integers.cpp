class Solution {
public:
    int getSum(int a, int b) {
        //Full adder using bitwise operation
        int c ;
        while(b!=0){
            c = a&b;
            a = a^b;
            b = c<<1;
        }
        return a;
    }
};
