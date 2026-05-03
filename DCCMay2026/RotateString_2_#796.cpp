class Solution {
public:
    bool rotateString(string s, string goal) {
        vector<int> indexes;
        int check_index = goal[0];

        int n = s.length();

        if(s.length() != goal.length()) return false;
        for(int i=0;i<n;i++){
            if(s[i] == check_index){
                indexes.push_back(i);
            }
        }

        for(auto& idx : indexes){
            bool check = true;
            for(int i = 0;i<n;i++){
                if(goal[i]!=s[(i+idx)%n]){
                    check = false;
                    break;
                }
            }
            if(check){
                return true;
            }
        }
        return false;
    }
};
