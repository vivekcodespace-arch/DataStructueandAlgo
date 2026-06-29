#include<bits/stdc++.h>
using namespace std;

int main(){

    int r,c;
    cin>>r>>c;
    vector<vector<int>> matrix(r, vector<int>(c));
    queue<pair<int,int>> q;
    int totalFreshApple = 0;
    for(int row = 0;row<r;row++){
        for(int col=0;col<c;col++){
            int temp;
            cin>>temp;
            if(temp == 2){
                q.push({row,col});
            }
            if(temp == 1){
                totalFreshApple++;
            }
            matrix[row][col] = temp; 
        }
    }

    vector<vector<int>> direction{{0,-1},{0,1},{-1,0},{1,0}};
    //first find all the rotten apples and put those index in the que
    int time = 0;
    while(!q.empty()){
        int N = q.size();
        while(N--){
            pair<int,int> front = q.front();
            int x = front.first;
            int y = front.second;
            q.pop();
            for(auto& dir: direction){
                int _x = x + dir[0];
                int _y = y + dir[1];
                auto check = [&](int x, int y) {
                    if((x < r && x>=0) && (y < c && y>=0)){
                        return true;
                    }
                    return false;
                };
                if(check(_x,_y) && matrix[_x][_y] == 1){
                    matrix[_x][_y] = 2;
                    q.push({_x,_y});
                    totalFreshApple--;
                }
            }
        }
        if(!q.empty()){
            time++;
        }
    }

    if(totalFreshApple){
        cout<<-1;
    }
    else{
        cout<<time;
    }
    return 0;
}