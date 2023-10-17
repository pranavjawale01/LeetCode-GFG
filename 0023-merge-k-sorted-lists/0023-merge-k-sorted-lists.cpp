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

class myCompare {
    public:
    bool operator()(const ListNode* a, const ListNode* b) {
        return (a->val > b->val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        priority_queue<ListNode*,vector<ListNode*>,myCompare> pq;
        for(int i=0;i<lists.size();i++) {
            if(lists[i]!=NULL) {
                pq.push(lists[i]);
            }
        }
        while(!pq.empty()) {
            auto least = pq.top();
            pq.pop();
            temp->next = least;
            temp = temp->next;
            if(least->next) {
                pq.push(least->next);
            }
        }
        return result->next;
    }
};