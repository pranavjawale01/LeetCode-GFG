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
        if (!head || !head->next) {
            return;
        }
        ListNode *temp = head;
        vector<int> arr;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        temp = head;
        int i = 0;
        while (temp && temp->next) {
            temp->val = arr[i];
            temp->next->val  = arr[n - i - 1];
            temp = temp->next->next;
            i++;
        }
        if (n % 2 != 0) {
            temp->val = arr[(n) / 2];
        }
    }
};