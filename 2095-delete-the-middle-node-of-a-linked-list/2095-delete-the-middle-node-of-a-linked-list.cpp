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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *slow = head, *fast = head;

        while (fast->next && fast->next->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next) {
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        ListNode *toDelete = slow;
        delete slow;
        return head;
    }
};