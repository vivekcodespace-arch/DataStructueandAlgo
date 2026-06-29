/* 
Consider this test case:
4 -> n
4  -> edges_count
[[0 2 1] [0 1 5] [1 2 1] [2 3 1]]
abaa = labels
2 = k   
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int, vector<pair<int,int>>> mp;
        for (auto& e : edges)
            mp[e[0]].push_back({e[1], e[2]});

        //let's print the adjancy list
        for(auto& x: mp){
            cout<<x.first<<"-> ";
            for(auto& y:x.second){
                cout<<'[';
                cout<<y.first<<","<<y.second;
                cout<<"]";
            }
            cout<<endl;

        }
        cout<<endl;
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // {cost, node, run}

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto t = pq.top(); pq.pop();
            int d = t[0], u = t[1], run = t[2];
            if (d > dist[u][run]) continue;

            for (auto& [v, w] : mp[u]) {
                int nr = (labels[u] == labels[v]) ? run + 1 : 1;
                if (nr > k) continue;
                if (d + w < dist[v][nr]) {
                    dist[v][nr] = d + w;
                    pq.push({d + w, v, nr});
                }
            }
        }

        int ans = INT_MAX;
        for (int c = 1; c <= k; c++) ans = min(ans, dist[n-1][c]);
        return ans == INT_MAX ? -1 : ans;
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