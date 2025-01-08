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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *ans = nullptr;
        function<void(TreeNode*)> solve = [&](TreeNode* rt) {
            if (!rt) return;
            if (rt->val == val) {
                ans = rt;
                return;
            }
            solve(rt->left);
            solve(rt->right);
        };
        solve(root);
        return ans;
    }
};