class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        unordered_map<int, int> mp;
        //O(mn)
        for (auto& row : boxGrid) {
            int n = row.size();
            int placing = n - 1;

            for (int i = n - 1; i >= 0; i--) {
                if (row[i] == '#') {
                    swap(row[i], row[placing]);
                    placing--;
                    continue;
                } else if (row[i] == '*') {
                    placing = i - 1;
                    continue;
                } else {
                    continue;
                }
            }
        }

        // for (auto& u : boxGrid) {
        //     for (auto& v : u) {
        //         cout << v << " ";
        //     }
        //     cout << endl;
        // }
        //now only i have to rotate the boxGrid


        int prev_row = boxGrid.size();
        int prev_col = boxGrid[0].size();

        vector<vector<char>> ans;

        for(int i= 0;i<prev_col;i++){
            vector<char> temp;
            for(int j=prev_row-1;j>=0;j--){
                temp.push_back(boxGrid[j][i]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
