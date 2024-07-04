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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        int sum = 0;
        head = head->next;
        
        while (head) {
            if (head->val == 0) {
                temp->next = new ListNode(sum);
                temp = temp->next;
                sum = 0;
            } else {
                sum += head->val;
            }
            head = head->next;
        }
        
        return ans->next;
    }
};