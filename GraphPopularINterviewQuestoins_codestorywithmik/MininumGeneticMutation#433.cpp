/*--------------------------------------------------------------------
//Problem link:https://leetcode.com/problems/minimum-genetic-mutation/
//Problem name: Minimum Genetic Mutation
---------------------------------------------------------------------*/


/* ********************************Remebmer*******************************
---If you are given a string and it said that you have to achienve a different string on modifying the given the string in minimum steps then it is a question of a BFS

Algorith:

At each level of the bfs traversal we are writing all the mutation from that level

1. Store the startGene in the queue and iterate until the queue is empty
2.Push all the mutation possible from a level 
3. Delete the visited string from the bank
4. If the end Gene is found return the level
*/

//In this solution we haven't used uordered_set by which searhing can be bit longer it can be optimized

//T.C - O(N*L*L) where N is the size of the bank and L is the length of the string
//S.C -	O(N)	
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = startGene.size();
        queue<string> q;
        q.push(startGene);
        int level = 1;

        while(!q.empty()){      //This can store max of the bank.size()
            int N = q.size();

            while(N--){
                string front = q.front();
                q.pop();
                //Get all the mutatoin from the front and check whether it exists in the bank , if it exists the push it in the queue and delete from the bank
                for(auto& c: "ACGT"){            // 4 times
                    for(int i=0;i<n;i++){	//Runs for the length of the string suppose L 
                        string temp = front;	//Copying a string also requires L T.C
                        temp[i] = c;
                        auto it = find(bank.begin(), bank.end(),temp);
                        if(it!=bank.end()){
                            if(temp == endGene) return level;
                            q.push(temp);
                            bank.erase(it);
                            
                        }
                    }
                }
                
                //So total T.C of this for block is L^2 and the queue is storing all those mutations which are in the bank so 
                //Total T.C (O(N * L * L))
            }
            level++;
            
        }

        return -1;
    }
};

//In this solution we have optimized the searing of the mutation which are generated in the mid of the program:
//T.C - O(N*L*L)
//S.C - O(N)
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        int level = 0;
        unordered_set<string> visited;
        
        queue<string> q;
        q.push(startGene);


        while(!q.empty()){
            int n = q.size();

            while(n--){
                string front = q.front();
                q.pop();

                if(front == endGene) return level;

                for(auto& c: "ACGT"){
                    for(int i=0;i<front.size();i++){
                        string temp = front;
                        temp[i] = c;
                        if(st.find(temp)!=st.end() && visited.find(temp)==visited.end()){
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                }

            }
            level++;
        }
        return -1;
    }
};
