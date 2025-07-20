/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* curr = head;
        ListNode* next;
        
        while(curr)
        {
            next = curr->next;
            if(next && curr->val == next->val)
            {
                curr->next=next->next;
                delete next;
                continue;
            }
            curr = curr->next;
        }
        return head;
    }
};