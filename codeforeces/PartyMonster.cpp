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
        cin>>a;
        vector<char> vec(a);

        for(int i=0;i<a;i++){
            cin>>vec[i];
        }


        stack<char> st;

        int i =0;
        while(i<a){
            if(st.size() && st.top()){
                char top = st.top();
                char curr = vec[i];

                if(top == '(' && curr ==')'){
                    st.pop();
                }
                else if(top == ')' && curr == '('){
                    st.pop();
                }
                else{
                    st.push(curr);
                }
            }
            else{
                st.push(vec[i]);
            }


            i++;
        }

        if(st.empty() == true){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}