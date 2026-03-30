class Solution {
public:
    vector<char> parent;
    vector<int> rank;

    char find(char u, vector<char>& parent){
        if(parent[u-'a'] == u){
            return u;
        }
        return parent[u-'a'] = find(parent[u-'a'],parent);
    }
    void Union(char x, char y, vector<char>& parent, vector<int>& rank){
        char x_parent = find(x, parent);
        char y_parent = find(y, parent);

        if(rank[x_parent-'a'] > rank[y_parent-'a']){
            parent[y_parent-'a'] = x_parent;
        }
        else if(rank[x_parent-'a'] < rank[y_parent-'a']){
            parent[x_parent-'a'] = y_parent;
        }
        else{
            parent[y_parent-'a']  = x_parent;
            rank[x_parent-'a']+=1;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        for(char start = 'a';start<='z';start++){
            parent[start-'a'] = start;
        }

        for(auto& eq: equations){
            char u = eq[0];
            char v = eq[3];
            char sign = eq[1];

            if(sign == '='){
                Union(u,v,parent,rank);
            }
            
        }



        for(auto& eq: equations){
            char u = eq[0];
            char v = eq[3];
            char sign = eq[1];

            if(sign == '!'){
                if(find(u,parent) == find(v,parent)){
                    return false;
                }
            }
            
        }
        
        return true;
    }
};
