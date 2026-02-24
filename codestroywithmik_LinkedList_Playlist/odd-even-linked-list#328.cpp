/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        
        ListNode* tempOdd = head;

        ListNode* tempEven = head->next;
        ListNode* evenHead = head->next;
        while(tempEven && tempEven->next){
            tempOdd->next = tempEven->next;
            tempOdd = tempEven->next;

            tempEven->next = tempOdd->next;
            tempEven = tempOdd->next;
        }
        tempOdd->next = evenHead;
        return head;
    }
};
