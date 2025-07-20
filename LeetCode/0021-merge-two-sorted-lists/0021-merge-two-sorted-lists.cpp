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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        
        ListNode* new_node = new ListNode();
        ListNode* mergedList = new_node;
        
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val <= list2->val) {
                new_node->val = list1->val;
                list1 = list1->next;
            }
            else {
                new_node->val = list2->val;
                list2 = list2->next;
            }
            
            if (list1 != nullptr || list2 != nullptr) {
                new_node->next = new ListNode();
                new_node = new_node->next;
            }
        }
        
        while(list1 != nullptr) {
            new_node->val = list1->val;
            list1 = list1->next;
            
            if (list1 != nullptr) {
                new_node->next = new ListNode();
                new_node = new_node->next;
            }
        }
        
        while(list2 != nullptr) {
            new_node->val = list2->val;
            list2 = list2->next;
            
            if (list2 != nullptr) {
                new_node->next = new ListNode();
                new_node = new_node->next;
            }
        }
        
        return mergedList;
    }
};