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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         unordered_map<ListNode*, int> mp;
//         while (head) {
//             mp[head]++;
//             if (mp[head] > 1) {
//                 return true;
//             }
//             head = head->next;
//         }
//         return false;
//     }
// };