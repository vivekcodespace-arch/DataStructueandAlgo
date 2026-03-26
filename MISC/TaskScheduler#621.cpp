class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxHeap;
        unordered_map<char,int> mp;


        for(auto& x: tasks){
            mp[x]+=1;
        }

        for(auto&x: mp){
            int freq = x.second;
            maxHeap.push(freq);
        }
        vector<int> vec;
        //when to terminate
        int cnt = 0;
        while(!maxHeap.empty()){
            vector<int> vec;
            for(int i=0;i<n+1;i++){
                if(maxHeap.empty()) break;
                else{
                    int top = maxHeap.top();
                    maxHeap.pop();
                    top--;
                    vec.push_back(top);
                }
            }
            for(auto& x: vec){
                if(x>0){
                    maxHeap.push(x);
                }
            }

            if(maxHeap.empty()){
                cnt += vec.size();
            }else{
                cnt += n+1;
            }


        }
        return cnt;  
    }
};
