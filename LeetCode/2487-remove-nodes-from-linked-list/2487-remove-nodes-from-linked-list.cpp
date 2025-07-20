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
    ListNode *reverse(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *last = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        int maxNode = -1;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr) {
            maxNode = max(maxNode, curr->val);
            if (curr->val < maxNode) {
                prev->next = curr->next;
                ListNode *temp = curr;
                curr = curr->next;
                delete temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return reverse(head);
    }
};



// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {
//         if (head == nullptr || head->next == nullptr) {
//             return head;
//         }
//         ListNode *nextNode = removeNodes(head->next);
//         if (head->val < nextNode->val) {
//             delete head;
//             return nextNode;
//         }
//         head->next = nextNode;
//         return head;
//     }
// };



// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {
//         ListNode *curr = head;
//         stack<ListNode*> st;
//         while (curr) {
//             st.push(curr);
//             curr = curr->next;
//         }
//         curr = st.top();
//         st.pop();
//         int maxNode = curr->val;
//         ListNode *resulthead = new ListNode(curr->val);
//         while (!st.empty()) {
//             curr = st.top();
//             st.pop();
//             if (curr->val < maxNode) {
//                 continue;
//             } else {
//                 ListNode *newNode = new ListNode(curr->val);
//                 newNode->next = resulthead;
//                 resulthead = newNode;
//                 maxNode = curr->val;
//             }
//         }
//         return resulthead;
//     }
// };



// class Solution {
// public:
//     ListNode* reverse(ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode* curr = head;
//         while (curr) {
//             ListNode* nxt = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nxt;
//         }
//         return prev;
//     }

//     ListNode* removeNodes(ListNode* head) {
//         if (!head) return nullptr;
        
//         head = reverse(head);
//         stack<int> st;
        
//         ListNode* current = head;
//         while (current) {
//             if (st.empty() || st.top() <= current->val) {
//                 st.push(current->val);
//             }
//             current = current->next;
//         }
        
//         ListNode* newHead = nullptr;
//         while (!st.empty()) {
//             ListNode* temp = new ListNode(st.top());
//             temp->next = newHead;
//             newHead = temp;
//             st.pop();
//         }
        
//         return reverse(newHead);
//     }
// };