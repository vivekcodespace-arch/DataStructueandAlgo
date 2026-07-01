//This question is of Bipartite graph but it's a modified and not too much similar to bipartite it's can be solve if a person doesn't know bipartite too.
//The logic is that you have to find which person is not a friend of any friend .

#include<bits/stdc++.h>
using namespace std;

//Drive code
int main(){
    int T;
    cin>>T;
    while(T--){
        int N,M;
        cin>>N>>M;
        vector<vector<char>> adj(N+1 , vector<char>(N+1, 0)); //1 for friend 0 for not a friend

        vector<vector<int>> edges;
        for(int i=0;i<M;i++){
            int a,b;
            cin>>a>>b;
            adj[a][b] = 1;
            adj[b][a] = 1;
        }
        
        vector<int> color(N+1, -1); //0 for table 1 and 1 for table 2
        bool possible = true;
        for(int start = 1;start < N+1 && possible; start++){
            if(color[start] != -1) continue;

            queue<int> q;
            q.push(start);
            color[start] = 0;

            while(!q.empty() && possible){
                int u = q.front();
                q.pop();

                for(int v= 1; v < N+1;v++){
                    if(u==v) continue;

                    if(adj[u][v] == 0){
                        if(color[v] == -1){
                            color[v] = 1-color[u];
                            q.push(v);
                        }
                        else if(color[v] == color[u]){
                            possible =false;
                            break;
                        }
                    }
                }

            }
        }

        cout<<(possible ? "YES\n" : "NO\n");

    }
    return 0;

}