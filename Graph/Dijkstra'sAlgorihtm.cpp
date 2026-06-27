//T.C = O(V * (log V  + (E*log V))) => O(V * (log V * (1 + E))) => O(V E log V)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //This dijkstra solution is not space optimized it stores different distance for same node we should remove the larger distance from the priority queue
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        //Create a adjacency list
        //edges ->  u,v,wt
        unordered_map<int, vector<pair<int,int>> > mp;//u -> {(v,wt),(v,wt)};
        for(auto& x: edges){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            
            mp[u].push_back({v,wt});
            mp[v].push_back({u, wt});
        }

        vector<int> res(V, INT_MAX);
        res[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> >  pq;
        //pq - {dist, node}
        pq.push({0,src});
        while(!pq.empty()){ // V 
            pair<int,int> top = pq.top();
            pq.pop();   //log(V)
            int dist = top.first;
            int node = top.second;

            for(auto & v : mp[node]){ //E
                int _node  = v.first;
                int _wt = v.second;

                if(dist + _wt < res[_node]){
                    res[_node ] = dist + _wt;
                    pq.push({dist+ _wt, _node}); //log(V)
                }
            }
        }

        return res;
    }

    //set implementation
    //we will be creating ordered set in ordered_set all elements are arranged in asceding order st.begin() will give us the min 
    vector<int> dijkstraSet(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        //Create a adjacency list
        //edges ->  u,v,wt
        unordered_map<int, vector<pair<int,int>> > mp;//u -> {(v,wt),(v,wt)};
        for(auto& x: edges){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            
            mp[u].push_back({v,wt});
            mp[v].push_back({u, wt});
        }

        vector<int> res(V, INT_MAX);
        res[src] = 0;
        set< pair<int,int> >  st;
        //st - {dist, node}
        st.insert({0,src});
        while(!st.empty()){
            pair<int,int> top = *st.begin();
            st.erase(st.begin());
            int dist = top.first;
            int node = top.second;

            for(auto & v : mp[node]){
                int _node  = v.first;
                int _wt = v.second;

                if(dist + _wt < res[_node]){
                    if(res[_node] != INT_MAX){
                        auto it = st.find({_wt, _node});
                        if(it != st.end()){
                            st.erase(it);
                        }
                    }
                    res[_node ] = dist + _wt;

                    st.insert({dist+ _wt, _node});
                }
            }


        }

        return res;
    }


};


//Driver code
int main()
{
    int T;
    Solution obj1;
    cin >> T;
    while (T--)
    {
        vector<vector<int>> edges;
        int V;
        cin >> V;
        int edges_count;
        cin >> edges_count;
        while (edges_count--)
        {
            int u;
            int v;
            int wt;
            cin >> u;
            cin >> v;
            cin >> wt;
            edges.push_back({u, v, wt});
        }
        int src;
        cin >> src;

        vector<int> res = obj1.dijkstraSet(V, edges, src);
        cout<<'[';
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] ;
            if(i != res.size()-1){
                cout<<",";
            }
        }
        cout<<']';
        cout<<" ";
    }

    return 0;
}