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
        int a;
        int b;
        cin>>a;
        cin>>b;

        if(a%2 == 0 && b%2 !=0){
            cout<<"YES"<<endl;
        }
        else if(a%2!=0 && b%2==0){
            cout<<"YES"<<endl;
        }
        else if(a%2 == 0 && b%2==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        

    }
    return 0;
}