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
    ListNode* removeZeroSumSublists(ListNode* head) {
        //unordered_map<prefixSum, ListNode*>
        unordered_map<int, ListNode*> mp;
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        mp[0] = dummyNode;
        int pSum = 0;

        while(head != NULL){
            pSum += head->val;

            if(mp.find(pSum)!= mp.end() ){
                cout<<"a"<<mp.size()<<"  ";
                ListNode* start = mp[pSum];
                ListNode* temp = start;
                int pre_sum = pSum;
                while(temp!=head){
                    temp = temp->next;
                    if(temp != head){
                        pre_sum = pre_sum + temp->val;
                        mp.erase(pre_sum);
                    }
                        
                }
                cout<<"b"<<mp.size()<<" ";
                start->next = head->next;
            }else{
                mp[pSum] = head;
            }
            head = head->next;
        }

        return dummyNode->next;
        
    }
};
