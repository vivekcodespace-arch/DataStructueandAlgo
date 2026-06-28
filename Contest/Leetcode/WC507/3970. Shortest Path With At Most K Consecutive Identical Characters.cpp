#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        //first you need to create adjaceny list
        unordered_map<int, vector<pair<int, int>>> mp;
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            mp[u].push_back({v,wt});
            
        }
        

        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq; //wt, node, currentK
        vector<int> res(n, INT_MAX);
        res[0] = 0;
        pq.push({0,0,1});
        while(!pq.empty()){
            vector<int> top = pq.top();
            pq.pop();
            
            int wt,u,currentK;
            wt = top[0];
            u = top[1];
            currentK = top[2];

            for(auto& x: mp[u]){
                int v = x.first;
                int _wt = x.second;
                if(labels[u] == labels[v] ){
                    currentK++;
                }
                if(currentK > k) continue;
                if(_wt + wt < res[v]){
                    res[v] = _wt + wt;
                    pq.push({wt+_wt, v , currentK});
                }

            }

        }

        return res[n-1];
    }
};

//Driver Code
int main(){
    // Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,3]], labels = "aab", k = 1

    Solution obj1;
    int T;
    cin>>T;

    while(T--){
        int n;
        cin >> n;
        int edges;
        cin>> edges;
        vector<vector<int>> edges_list;
        while(edges--){
            int u,v,wt;
            cin >>u>>v>>wt;
            edges_list.push_back({u,v,wt});
        }
        string labels;
        cin>>labels;
        int k;
        cin>>k;
        int res = obj1.shortestPath(n,edges_list, labels, k);
        cout<<res<<endl;
        

    }
    return 0;
}