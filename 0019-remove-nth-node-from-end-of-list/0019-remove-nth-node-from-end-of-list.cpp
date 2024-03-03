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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        for (int i = 1; i <= n; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            ListNode* temp1 = head->next;
            delete(head);
            return temp1;
        }
        ListNode* prev = head;
        while (temp != nullptr && temp->next != nullptr) {
            prev = prev->next;
            temp = temp->next;
        }
        ListNode* delNode = prev->next;
        prev->next = prev->next->next;
        delete(delNode);
        return head;
    }
};

// class Solution {
// public:
//     int getLengthOfLinkedList(ListNode* head) {
//         int count = 0;
//         while (head != nullptr) {
//             head = head->next;
//             count++;
//         }
//         return count;
//     }
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int l = getLengthOfLinkedList(head);
//         if (l == n) {
//             ListNode* temp = head->next;
//             delete(head);
//             return temp;
//         }
//         l -= n;
//         ListNode* temp = head;
//         ListNode* prev = nullptr;
//         while (l--) {
//             prev = temp;
//             temp = temp->next;
//         }
//         prev->next = temp->next;
//         delete(temp);
//         return head;
//     }
// };