#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while (t--) {  
        //code starts from here
        int x ,y;
        cin>>x;
        cin>>y;

        bool flag = false;
        for(int z=x+1;z<y;z++){
            // cout<<z<<"->"<<y%z<<",";
            if(z%x == 0 && y%z!=0){

                cout<<"YES"<<endl;
                flag = true;
                break;
            }
        }
        if(!flag)
            cout<<"NO"<<endl;
    }


    return 0;
}