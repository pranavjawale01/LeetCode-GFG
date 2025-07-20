/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, int a, int b) {
        if (!root) {
            return nullptr;
        }
        if (root->val == a || root->val == b) {
            return root;
        }
        TreeNode *l = solve(root->left, a, b);
        TreeNode *r = solve(root->right, a, b);
        if (l && r) {
            return root;
        }
        return l ? l : r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p->val, q->val);
    }
};