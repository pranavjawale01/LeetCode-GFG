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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode *ans = new ListNode(head->val);
        head = head->next;
        ListNode *temp = ans;

        while (head) {
            if (head->val == temp->val) {
                head = head->next;
            } else {
                ListNode *nxt = new ListNode(head->val);
                temp->next = nxt;
                temp = nxt;
                head = head->next;
            }
        }
        delete head;
        return ans;
    }
};
