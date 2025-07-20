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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int currPos = 1;
        int prevPos = 0;
        int firstPos = 0;
        int minDist = INT_MAX;
        while (curr && curr->next) {
            if ((curr->val < prev->val && curr->val < curr->next->val) || (curr->val > prev->val && curr->val > curr->next->val)) {
                if (prevPos == 0) {
                    prevPos = currPos;
                    firstPos = currPos;
                } else {
                    minDist = min(minDist, currPos - prevPos);
                    prevPos = currPos;
                }
            }
            currPos++;
            prev = curr;
            curr = curr->next;
        }
        if (minDist == INT_MAX) {
            return {-1, -1};
        }
        return {minDist, prevPos - firstPos};
    }
};