#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        int start = occupiedIntervals[0][0];
        int end = occupiedIntervals[0][1];
        int n = occupiedIntervals.size();
        vector<vector<int>> res;
        for(int i =1 ;i <n; i++){
            if(end + 1 >= occupiedIntervals[i][0]){
                start = min(start, occupiedIntervals[i][0]);
                end = max(end , occupiedIntervals[i][1]);
                continue;
            }
            else{
                res.push_back({start, end});
                start = occupiedIntervals[i][0];
                end = occupiedIntervals[i][1];
            }
        }
        res.push_back({start, end});
        //Now i have remove from freeStart to freeEnd
        int i = 0;
        while(i< res.size()){
            int start = res[i][0];
            int end = res[i][1];
            if(freeStart <= start && freeEnd >= end){
                res.erase(res.begin()+i);
            }
            else if(freeStart > start && freeEnd < end){
                //In this case two intervals will be made
                res.erase(res.begin()+i);
                res.insert(res.begin()+i, {start, freeStart-1});
                res.insert(res.begin()+i+1, {freeEnd+1, end});
                i+=2;   
            }
            else if(freeStart <= end && freeEnd >= end){
                res[i][1] = freeStart - 1;
                i++;
            }
            else if(freeEnd >= start && freeStart <= start){
                res[i][0] = freeEnd + 1;
                i++;
            }
            else{
                i++;
            }

        }
        return res;
    }
};
int main(){

    Solution obj1;
    vector<vector<int>> vec{{2,6},{4,8},{10,10},{10,12},{14,16}};
    int freeStart = 7;
    int freeEnd = 11;
    vector<vector<int>> res  = obj1.filterOccupiedIntervals(vec, freeStart, freeEnd);
    for(auto& x: res){
        cout<<"[";
        for(auto& y: x){
            cout<<y<<" ";
        }
        cout<<"],";
    }
    return 0;
}