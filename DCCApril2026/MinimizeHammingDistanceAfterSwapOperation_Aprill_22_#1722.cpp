class Solution {
public:
    //first i have to write union and find code
    
    int find(int i, vector<int>& parent){
        if(parent[i] == i) return i;

        return parent[i] = find(parent[i], parent);
    }
    void Union(int x, int y, vector<int>& parent, vector<int>& rank){
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if(x_parent == y_parent){
            return ;
        }
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }

        // return true;//if union has happened

    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        //Union all of the allowables 
        int n = source.size();
        vector<int> parent;
        vector<int> rank(n,0);

        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        for(auto& allowed: allowedSwaps){
            int u = allowed[0];
            int v = allowed[1];
            Union(u,v,parent,rank);
        }
        int diff=0;

        unordered_map<int, unordered_map<int,int>> mp;
        for(int i=0;i<n;i++){
            int curr = source[i];
            int par = find(i, parent);

            mp[par][curr]++;
        }
        for(int i=0;i<n;i++){

            int t = target[i];

            int grp = find(i, parent);
            if(mp[grp].find(t) != mp[grp].end() && mp[grp][t]!=0){
                mp[grp][t]--;
            }else{
                diff++;
            }

        }

        return diff;
        
    }
};
