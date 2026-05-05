//1st approach has more time because you are iteratig  k*n time 

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
    //This will be a function which will give me the last ListNode
    ListNode* lastmem(ListNode* head)
    {
        while(head->next->next!=NULL)
        {
            head=head->next;
        }
        ListNode* temp=head->next;
        head->next=NULL;
        return temp;
    }
    int LLlength(ListNode* head)
    {
        int count=0;
        while(head)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        k=k%LLlength(head);
        while(k){
            //Write the code here
            ListNode* getLast=lastmem(head);
            getLast->next=head;
            head=getLast;
            k--;
        }
        return head;
    }
};


//O(n) approach

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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;

        while(temp){
            n++;
            temp = temp->next;
        }
        if(n == 1 || n == 0) return head;
        k = k%n;
        if(k==0) return head;
        int prev_index = n-k;
        int first_index = n-k+1;
        int last_index = n;
        ListNode* prev = nullptr;
        ListNode* first = nullptr;
        ListNode* last = nullptr;
        temp = head;
        n = 0;
        while(temp){
            n++;

            if(n == prev_index){
                prev = temp;
            }
            if(n == first_index){
                first = temp;
            }
            if(n == last_index){
                last = temp;
            }

            temp = temp->next;
        }

        last->next = head;
        prev->next = nullptr;
        head = first;

        return head;
    }
};
