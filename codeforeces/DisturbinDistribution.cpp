#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;

    while(t--){

        int size;
        cin>>size;
        vector<int> arr(size);

        for(int i=0;i<size;i++){
            cin>>arr[i];
        }

        int cnt = 0;
        for(int i=0;i<size;i++){
            if(i!=size-1 && arr[i] == 1){
                continue;
            }
            cnt+=arr[i];
        }

        cout<<cnt<<endl;

    }

    return 0;
}