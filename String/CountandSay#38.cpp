class Solution {
public:
    string solve(string s){
        int i=0;
        int n = s.length();
        string newstr;
        while(i<n){

            int cnt = 1;
            char no = s[i];

            while(i+1 < n && s[i+1] == s[i]){
                cnt++;
                i++;
            }
            newstr += to_string(cnt);
            newstr +=  no;
            i++;
        }

        return newstr;
    }
    string countAndSay(int n) {
        
        if(n == 1){
            return "1";
        }

        return solve(countAndSay(n-1));
    }
};
