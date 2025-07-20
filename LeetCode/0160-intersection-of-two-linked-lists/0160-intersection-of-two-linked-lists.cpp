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
    int getDifference(ListNode* head1, ListNode* head2) {
        int len1 = 0, len2 = 0;
        
        while (head1 != NULL) {
            ++len1;
            head1 = head1->next;
        }
        
        while (head2 != NULL) {
            ++len2;
            head2 = head2->next;
        }
        
        return len1 - len2;
    }
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int diff = getDifference(head1, head2);
    
        if (diff < 0) {
            while (diff++ != 0) {
                head2 = head2->next;
            }
        } else {
            while (diff-- != 0) {
                head1 = head1->next;
            }
        }
        
        while (head1 != NULL && head2 != NULL) {
            if (head1 == head2) {
                return head1;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        
        return NULL;
    }
};










// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_set<ListNode*> st;
//         while (headA) {
//             st.insert(headA);
//             headA = headA->next;
//         }
//         while (headB) {
//             if (st.find(headB) != st.end()) {
//                 return headB;
//             }
//             headB = headB->next;
//         }
//         return nullptr;
//     }
// };