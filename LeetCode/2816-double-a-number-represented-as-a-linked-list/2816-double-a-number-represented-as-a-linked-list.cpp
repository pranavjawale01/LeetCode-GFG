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
    ListNode* doubleIt(ListNode* head) {
        if (head->val >= 5) {
            ListNode *newHead = new ListNode(0);
            newHead->next = head;
            head = newHead;
        }
        ListNode *curr = head;
        ListNode *prev = nullptr;

        while (curr != nullptr) {
            int newVal = curr->val * 2;
            if (newVal < 10) {
                curr->val = newVal;
            } else if (prev != nullptr) {
                curr->val = newVal % 10;
                prev->val += 1;
            } else {
                ListNode *newHead = new ListNode(1);
                newHead->next = curr;
                curr->val = newVal % 10;
                head = newHead;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};







// class Solution {
// public:
//     ListNode* doubleIt(ListNode* head) {
//         ListNode *curr = head;
//         ListNode *prev = nullptr;

//         while (curr != nullptr) {
//             int newVal = curr->val * 2;
//             if (newVal < 10) {
//                 curr->val = newVal;
//             } else if (prev != nullptr) {
//                 curr->val = newVal % 10;
//                 prev->val += 1;
//             } else {
//                 ListNode *newHead = new ListNode(1);
//                 newHead->next = curr;
//                 curr->val = newVal % 10;
//                 head = newHead;
//             }
//             prev = curr;
//             curr = curr->next;
//         }
//         return head;
//     }
// };



// class Solution {
// public:
//     int solve(ListNode* head) {
//         if (!head) {
//             return 0;
//         }
//         int carry = solve(head->next);
//         int newVal = (head->val) * 2 + carry;
//         head->val = newVal % 10;
//         return newVal / 10;
//     }
//     ListNode* doubleIt(ListNode* head) {
//         int lastCarry = solve(head);
//         if (lastCarry > 0) {
//             ListNode *newhead = new ListNode(lastCarry);
//             newhead->next = head;
//             return newhead;
//         }
//         return head;
//     }
// };



// class Solution {
// public:
//     ListNode* reverse(ListNode *head) {
//         if (!head || !head->next) {
//             return head;
//         }
//         ListNode* last = reverse(head->next);
//         head->next->next = head;
//         head->next = nullptr;

//         return last;
//     }
//     ListNode* doubleIt(ListNode* head) {
//         head = reverse(head);
//         ListNode* curr = head;
//         ListNode* prev = nullptr;
//         int carry = 0;
//         while (curr) {
//             int newValue = curr->val * 2 + carry;
//             curr->val = newValue % 10;
//             if (newValue >= 10) {
//                 carry = 1;
//             } else {
//                 carry = 0;
//             }
//             prev = curr;
//             curr = curr->next;
//         }
//         if (carry != 0) {
//             ListNode *newHead = new ListNode(carry);
//             prev->next = newHead;
//         }
//         return reverse(head);
//     }
// };