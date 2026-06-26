#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int cnt = 0;
        sort(points.begin(), points.end());
        int n = points.size();
        if(n == 0) return 0;

        for(int i = 0;i<n;i++){
            int start = points[i][0];
            int end = points[i][1];

            if(i+1 < n && points[i+1][0] > end){
                cnt++;
            }
        }
        return cnt + 1;
    }
};

int main(){
    int T;
    cin >> T;
    Solution obj1;
    while(T--){
        vector<vector<int>> points;
        int no_of_points;
        cin>> no_of_points;
        while (no_of_points--)
        {
            int a;
            int b;
            cin>>a;
            cin>>b;
            points.push_back({a,b});
        }
        int res = obj1.findMinArrowShots(points);
        cout<<res;
        cout<<endl;
        
    }
}