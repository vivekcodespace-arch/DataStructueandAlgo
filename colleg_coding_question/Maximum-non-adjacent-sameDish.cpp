int main(){
    
    unordered_map<int,pair<int,int>> mp;
    vector<int> v{1,2,1,2,1,2,3,4,3,4,3,4,4,4};
    int n = v.size();
    
    for(int i=0;i<n;i++){
        
        if(mp.find(v[i])!=mp.end()){
            if(mp[v[i]].first == i-1){
                continue;
            }
            mp[v[i]] = make_pair(i,mp[v[i]].second+1);
        }else{
            mp[v[i]] = make_pair(i,1);
        }
    }
    
    for(auto& x:mp){
        cout<<x.first<<"-> "<<x.second.first<<","<<x.second.second<<endl;
    }
    vector<pair<int,pair<int,int>>> vmap(mp.begin(),mp.end());
    //Now i have to arrange the it in desceding order
    sort(vmap.begin(),vmap.end(),[](auto& x,auto& y){
        if(x.second.second==y.second.second){
            return x.first < y.first;
        }
        return x.second.second>y.second.second;
        
    });
    cout<<"\nThe vector\n";
    for(auto& x: vmap){
        cout<<x.first<<"->"<<x.second.first<<","<<x.second.second<<endl;
    }
    cout<<"The answer is-> "<<vmap[0].first;
}

// int main(){
//     vector<int> v{1,2,3,4,5};
//     sort(v.begin(),v.end(),[](auto& a,auto& b){
//        return a>b; 
//     });
//     for(auto& x: v){
//         cout<<x<<" ";
//     }
// }
