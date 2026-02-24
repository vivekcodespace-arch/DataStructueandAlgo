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
//Optimal Approach
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }
};
