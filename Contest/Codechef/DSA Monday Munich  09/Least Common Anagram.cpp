#include<bits/stdc++.h>
using namespace std;
int main(){

    int T;
    cin>>T;
    vector<string> v;
    while(T--){
        string temp;
        cin>>temp;
        v.push_back(temp);
    }


    int n = v.size();
    vector<vector<int>> arr(n, vector<int>(27,0));

    for(int i=0;i<n;i++){
        for(auto& c: v[i]){
            arr[i][c - 'a']++;
        }
    }
    
    vector<char> res;

    for(auto& c :  v[0]){
        //check if this c is present in all the string if in any not found then continue
        bool present = true;
        for(int i=0;i<n;i++){
            if(arr[i][c-'a'] <= 0){
                present = false;
                break;
            }
        }
         
        if(present){
            //decrement 1 from all of that
            for(int i=0;i<n;i++){
                arr[i][c-'a']--;
                
            }
            res.push_back(c);
        }
    }
    if(res.size()==0){
        cout<<"no such string";
    }
    sort(res.begin(), res.end());
    for(auto& c: res){
        cout<<c;
    }

    return 0;
}