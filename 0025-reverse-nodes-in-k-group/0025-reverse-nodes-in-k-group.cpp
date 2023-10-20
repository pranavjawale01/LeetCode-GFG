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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* result = new ListNode(0);
        result->next = head;
        ListNode* prevGroupEnd = result;
        ListNode* curr = head;
        int length = 0;
        while (head != nullptr) 
        {
            length++;
            head = head->next;
        }
        head = result->next;
        for (int i = 0; i < length / k; ++i) 
        {
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* groupEnd = groupStart;
            ListNode* next = nullptr;
            for (int j = 0; j < k; ++j) 
            {
                next = curr->next;
                curr->next = groupStart;
                groupStart = curr;
                curr = next;
            }
            prevGroupEnd->next = groupStart;
            groupEnd->next = curr;
            prevGroupEnd = groupEnd;
        }
        return result->next;
    }
};