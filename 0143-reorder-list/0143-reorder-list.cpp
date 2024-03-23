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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr, *curr = slow->next, *next;
        slow->next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode *first = head, *second = prev;
        while (first && second) {
            ListNode *firstNext = first->next;
            ListNode *secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};

// class Solution {
// public:
//     ListNode *curr = nullptr;
//     void solve(ListNode *head) {
//         if (head == nullptr) {
//             return;
//         }
//         solve(head->next);
//         ListNode *temp = curr->next;
//         if (curr->next == nullptr) {
//             return;
//         } else if (curr == head) {
//             head->next = nullptr;
//             return;
//         }
//         curr->next = head;
//         head->next = (temp == head) ? nullptr : temp;
//         curr = temp;
//     }
//     void reorderList(ListNode* head) {
//         curr = head;
//         solve(head);
//     }
// };


// // class Solution {
// // public:
// //     void reorderList(ListNode* head) {
// //         stack<ListNode*> st;
// //         ListNode *curr = head;
// //         while (curr) {
// //             st.push(curr);
// //             curr = curr->next;
// //         }
// //         int k = st.size() / 2;
// //         curr = head;
// //         while (k--) {
// //             ListNode *topNode = st.top();
// //             st.pop();

// //             ListNode *temp = curr->next;
// //             curr->next = topNode;
// //             topNode->next = temp;
// //             curr = temp;
// //         }
// //         curr->next = nullptr;
// //     }
// // };

// // // class Solution {
// // // public:
// // //     ListNode *reverse(ListNode *head) {
// // //         if (head == nullptr || head->next == nullptr) {
// // //             return head;
// // //         }
// // //         ListNode *last = reverse(head->next);
// // //         head->next->next = head;
// // //         head->next = nullptr;
// // //         return last;
// // //     }
// // //     void reorderList(ListNode* head) {
// // //         ListNode *slow = head, *fast = head;
// // //         while (fast && fast->next) {
// // //             slow = slow->next;
// // //             fast = fast->next->next;
// // //         }
// // //         ListNode *rev= reverse(slow);
// // //         ListNode *curr = head;
// // //         while (rev->next != nullptr) {
// // //             ListNode *tempcurr = curr->next;
// // //             curr->next = rev;

// // //             ListNode *temprev = rev->next;
// // //             rev->next = tempcurr;

// // //             curr = tempcurr;
// // //             rev = temprev;
// // //         }
// // //     }
// // // };

// // // // class Solution {
// // // // public:
// // // //     void reorderList(ListNode* head) {
// // // //         if (!head || !head->next) {
// // // //             return;
// // // //         }
// // // //         ListNode *temp = head;
// // // //         vector<int> arr;
// // // //         while (temp) {
// // // //             arr.push_back(temp->val);
// // // //             temp = temp->next;
// // // //         }
// // // //         int n = arr.size();
// // // //         temp = head;
// // // //         int i = 0;
// // // //         while (temp && temp->next) {
// // // //             temp->val = arr[i];
// // // //             temp->next->val  = arr[n - i - 1];
// // // //             temp = temp->next->next;
// // // //             i++;
// // // //         }
// // // //         if (n % 2 != 0) {
// // // //             temp->val = arr[(n) / 2];
// // // //         }
// // // //     }
// // // // };