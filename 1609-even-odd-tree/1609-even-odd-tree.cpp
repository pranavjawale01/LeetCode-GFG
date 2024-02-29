/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        bool even = true;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int prev;
            if (even) {
                prev = INT_MIN;
            } else {
                prev = INT_MAX;
            }
            while (n--) {
                TreeNode* temp = q.front();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                q.pop();
                if (even && (temp->val % 2 == 0 || temp->val <= prev)) {
                    return false;
                }
                if (!even && (temp->val % 2 != 0 || temp->val >= prev)) {
                    return false;
                }
                prev = temp->val;
            }
            even = !even;
        }
        return true;
    }
};