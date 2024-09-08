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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode *temp = head;
        while (temp) {
            temp = temp->next;
            len++;
        }

        int partSize = len / k;
        int extraNodes = len % k;

        vector<ListNode*> ans(k, nullptr);
        temp = head;

        for (int i = 0; i < k; ++i) {
            if (!temp) break;
            ans[i] = temp;

            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0);
            extraNodes--;

            for (int j = 1; j < currentPartSize; ++j) {
                temp = temp->next;
            }

            ListNode* nextPart = temp->next;
            temp->next = nullptr;
            temp = nextPart;
        }

        return ans;
    }
};