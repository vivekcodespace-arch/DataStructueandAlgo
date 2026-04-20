class Solution {
public:
    int maxDistance(vector<int>& colors) {
        vector<pair<int,int>> vec; //first one store the no. and second one stores the index
        //if that no. is found then don't store it
        vector<bool> visited(101,false);
        int res = 0;
        for(int i=0;i<colors.size();i++){
            if(!visited[colors[i]]){
                visited[colors[i]] = true;
                vec.push_back({colors[i],i});
            }
                //you start iterating from the beginning of the vec array and as soon as you find the first match break from thre
            for(auto& x: vec){
                int number = x.first;
                int index = x.second;
                if(number!=colors[i]){
                    res = max(res, abs(index-i));
                }
            }
        }
        return res;
    }
};
