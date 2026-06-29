#include<bits/stdc++.h>
using namespace std;


int main(){

    int N;
    cin>>N;
    vector<int> arr;
    int n = N;
    while(n--){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }


    vector<int> maxarr(N);
    int maxElement = INT_MIN;
    for(int i=N-1;i>=0;i--){
        if(arr[i] > maxElement){
            maxElement = arr[i];
        }
        // maxElement = max(maxElement, arr[i]);
        maxarr[i] = maxElement;
    }

    for(int i=0;i<N;i++){
        if(i+1 == N){
            cout<<arr[i]<<" ";
            continue;
        }
        if(arr[i] > maxarr[i+1]){
            cout<<arr[i]<<" ";
        }
    }


    return 0;
}