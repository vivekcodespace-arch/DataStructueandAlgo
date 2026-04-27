class Solution {
public:
    int root_result = 0;
    vector<int> result ;
    int N;
    vector<int> count;
    int dfsBase(unordered_map<int,vector<int>>& mp,int curr_node,int prev_node, int curr_depth){
        int total_node = 1;

        root_result += curr_depth;

        for(auto& child: mp[curr_node]){
            if(child == prev_node)
                continue;
            total_node += dfsBase(mp, child, curr_node, curr_depth+1);
        }

        count[curr_node] = total_node;

        return total_node;
    }

    void findDist(unordered_map<int,vector<int>>& mp, vector<int>& result,int parent_node,int prev_node){
        for(auto& child : mp[parent_node]){

            if(child == prev_node){
                continue;
            } 

            result[child] = result[parent_node] - count[child] + (N - count[child]);

            findDist(mp,result,child,parent_node);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        //fist let's populate the adjacency list
        N = n;

        result.resize(N,0);
        count.resize(N,0);
        unordered_map<int, vector<int>> mp;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        dfsBase(mp,0,-1,0);
        result[0] = root_result;
        findDist(mp,result,0,-1);

        return result;


    }
};
