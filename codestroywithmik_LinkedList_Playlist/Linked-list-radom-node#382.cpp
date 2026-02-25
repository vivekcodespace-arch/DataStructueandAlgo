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
    //Brute force approach 
    // Store the linked list in an array and return the random no. from the array
    vector<int> arr;
    mt19937 gen;
    Solution(ListNode* head) {
        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
    }

    int getRandom() {
        uniform_int_distribution<int> dist(0, arr.size() - 1);
        return arr[dist(gen)];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
//Reservoir sampling method the better approach to this prob
