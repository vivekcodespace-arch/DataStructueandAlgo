class Solution {
public:
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        ListNode* temp = node -> next;
        node -> next = node -> next -> next;
        delete temp;
    }
};
//2ns solution using while loop conventional type method
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next->next){
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        node->next = nullptr;
    }
};

//More book like explanantion 

