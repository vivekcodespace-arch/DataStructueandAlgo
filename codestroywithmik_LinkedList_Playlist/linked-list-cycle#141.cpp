class Solution {
public:
    bool hasCycle(ListNode *head) {
        //Brute force method
        unordered_set<ListNode*> st;
        ListNode* temp = head;

        while(temp){
            if(st.count(temp)){
                return true;
            }
            st.insert(temp);
            temp = temp->next;
        }
        return false;
        
    }
};
