vector<int> removeZeroSumSubarrays(vector<int>& arr) {
    unordered_map<int,int> mp;
    vector<int> result;

    int prefix = 0;

    mp[0] = -1;

    for(int i = 0; i < arr.size(); i++) {
        prefix += arr[i];

        if(mp.find(prefix) != mp.end()) {
            int idx = mp[prefix];
            prefix -= arr[i];
            while(result.size() > idx + 1) {
                mp.erase(prefix);
                prefix -= result.back();
                result.pop_back();
            }
        }
        else {
            result.push_back(arr[i]);
            mp[prefix] = result.size() - 1;
        }
    }

    return result;
}
int main(){
    vector<int> x{1,4,5,6,-6,-5,-4};
    vector<int> res;
    res = removeZeroSumSubarrays(x);
    for(auto& x: res){
        cout<<x<<" ";
    }
    
}
