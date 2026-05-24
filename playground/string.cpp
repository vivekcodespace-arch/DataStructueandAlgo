#include<bits/stdc++.h>
using namespace std;
string solve(string s){
        int i=0;
        int n = s.length();
        string newstr = "";
        while(i<n){

            int cnt = 1;
            char no = s[i];

            while(i+1 < n && s[i+1] == s[i]){
                cnt++;
                i++;
            }
            
            newstr += to_string(cnt);
            newstr +=  no;
            i++;
        }

        return newstr;
    }
int main(){
    cout<<solve("111223");
    return 0;
}