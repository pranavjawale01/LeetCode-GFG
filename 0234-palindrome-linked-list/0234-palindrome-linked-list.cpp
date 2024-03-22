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

// Using Vector
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        ListNode *temp = head;
        while (temp != nullptr) {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp != nullptr) {
            if (vec.back() == temp->val) {
                temp = temp->next;
                vec.pop_back();
            } else {
                return false;
            }
        }
        return true;
    }
};

// // Using Stack
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         stack<int> st;
//         ListNode* temp = head;
//         while (temp != nullptr) {
//             st.push(temp->val);
//             temp = temp->next;
//         }
//         temp = head;
//         while (temp != nullptr) {
//             if (temp->val == st.top()) {
//                 temp = temp->next;
//                 st.pop();
//             } else {
//                 return false;
//             }
//         }
//         return true;
//     }
// };