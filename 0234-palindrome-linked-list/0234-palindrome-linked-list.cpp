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

// without changing data structure
class Solution {
public:
    ListNode *curr;
    bool solve(ListNode *head) {
        if (!head) {
            return true;
        }
        if (!solve(head->next) || head->val != curr->val) {
            return false;
        }
        curr = curr->next;
        return true;
    }
    bool isPalindrome(ListNode* head) {
        curr = head;
        return solve(head);
    }
};

// one pass solution
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         if (!head || !head->next) {
//             return head;
//         }
//         ListNode *slow = head;
//         ListNode *fast = head;
//         ListNode *prev = nullptr;
//         while (fast && fast->next) {
//             fast = fast->next->next;
//             ListNode *temp = slow->next;
//             slow->next = prev;
//             prev = slow;
//             slow = temp;
//         }
//         if (fast) {
//             slow = slow->next;
//         }
//         while (prev && slow) {
//             if (prev->val != slow->val) {
//                 return false;
//             }
//             prev = prev->next;
//             slow = slow->next;
//         }
//         return true;
//     }
// };

// // two pass solution 
// // class Solution {
// // public:
// //     ListNode *reverse(ListNode* head) {
// //         if (!head || !head->next) {
// //             return head;
// //         }
// //         ListNode *prev = nullptr;
// //         ListNode *curr = head;
// //         ListNode *nxt = nullptr;
// //         while (curr != nullptr) {
// //             nxt = curr->next;
// //             curr->next = prev;
// //             prev = curr;
// //             curr = nxt;
// //         }
// //         return prev;
// //     }
// //     bool isPalindrome(ListNode* head) {
// //         if (!head || !head->next) {
// //             return true;
// //         }
// //         ListNode *fast = head;
// //         ListNode *slow = head;
// //         ListNode *prev = nullptr;
// //         while (fast && fast->next) {
// //             fast = fast->next->next;
// //             prev = slow;
// //             slow = slow->next;
// //         }
// //         prev->next = nullptr;
// //         // if (fast) {
// //         //     slow = slow->next;
// //         // }
// //         slow = reverse(slow);
// //         prev = head;
// //         while (prev) {
// //             if (prev->val == slow->val) {
// //                 prev = prev->next;
// //                 slow = slow->next;
// //             } else {
// //                 return false;
// //             }
// //         }
// //         return true;
// //     }
// // };

// // // Using Vector
// // // class Solution {
// // // public:
// // //     bool isPalindrome(ListNode* head) {
// // //         vector<int> vec;
// // //         ListNode *temp = head;
// // //         while (temp != nullptr) {
// // //             vec.push_back(temp->val);
// // //             temp = temp->next;
// // //         }
// // //         temp = head;
// // //         while (temp != nullptr) {
// // //             if (vec.back() == temp->val) {
// // //                 temp = temp->next;
// // //                 vec.pop_back();
// // //             } else {
// // //                 return false;
// // //             }
// // //         }
// // //         return true;
// // //     }
// // // };

// // // // // Using Stack
// // // // class Solution {
// // // // public:
// // // //     bool isPalindrome(ListNode* head) {
// // // //         stack<int> st;
// // // //         ListNode* temp = head;
// // // //         while (temp != nullptr) {
// // // //             st.push(temp->val);
// // // //             temp = temp->next;
// // // //         }
// // // //         temp = head;
// // // //         while (temp != nullptr) {
// // // //             if (temp->val == st.top()) {
// // // //                 temp = temp->next;
// // // //                 st.pop();
// // // //             } else {
// // // //                 return false;
// // // //             }
// // // //         }
// // // //         return true;
// // // //     }
// // // // };