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
    int numComponents(ListNode* head, vector<int>& nums) {
        int count = 0;
        unordered_set<int> st(nums.begin(), nums.end());

        while (head) {
            bool flag = false;
            while (head && st.find(head->val) != st.end()) {
                flag = true;
                head = head->next;
            }
            if (flag) {
                count++;
            }
            if (head) {
                head = head->next;
            }
        }
        return count;
    }
};








// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     int numComponents(ListNode* head, vector<int>& nums) {
//         int count = 0;
//         unordered_set<int> st(nums.begin(), nums.end());
//         bool inComponent = false;

//         while (head) {
//             if (st.find(head->val) != st.end()) {
//                 if (!inComponent) {
//                     count++;
//                     inComponent = true;
//                 }
//             } else {
//                 inComponent = false;
//             }
//             head = head->next;
//         }
//         return count;
//     }
// };