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
    ListNode* merge(ListNode* L1, ListNode* L2){
        if(L1 == NULL) return L2;
        if(L2 == NULL) return L1;
        if(L1->val <= L2->val){
            L1-> next = merge(L1->next, L2);
            return L1;
        }
        else{
            L2->next = merge(L1 , L2->next);
            return L2;
        }
    }
    ListNode* partitionAndMerge(int s, int e, vector<ListNode*>& lists ){
        if(s == e){
            return lists[s];
        }
        int m = s + (e-s)/2;

        ListNode* L1  = partitionAndMerge(s , m , lists);
        ListNode* L2 = partitionAndMerge(m+1 ,e, lists);

        return merge(L1, L2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return nullptr;
        return partitionAndMerge(0, lists.size()-1, lists);
    }
};
