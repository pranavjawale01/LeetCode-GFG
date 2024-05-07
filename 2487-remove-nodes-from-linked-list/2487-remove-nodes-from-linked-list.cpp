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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        if (!head) return nullptr;
        
        head = reverse(head);
        stack<int> st;
        
        ListNode* current = head;
        while (current) {
            if (st.empty() || st.top() <= current->val) {
                st.push(current->val);
            }
            current = current->next;
        }
        
        ListNode* newHead = nullptr;
        while (!st.empty()) {
            ListNode* temp = new ListNode(st.top());
            temp->next = newHead;
            newHead = temp;
            st.pop();
        }
        
        return reverse(newHead);
    }
};