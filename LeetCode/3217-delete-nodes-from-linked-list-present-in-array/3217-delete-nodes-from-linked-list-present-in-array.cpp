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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st(nums.begin(), nums.end());
        while (head && st.find(head->val) != st.end()) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        
        if (!head) {
            return nullptr;
        }
        
        ListNode *prev = head;
        ListNode *temp = head->next;
        
        while (temp) {
            if (st.find(temp->val) != st.end()) {
                prev->next = temp->next;
                ListNode* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        
        return head;
    }
};