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
    int maxDepth(TreeNode* root) {
        int ans = 0;
        function<void(TreeNode*, int)> solve = [&](TreeNode *rt, int count) {
            if (!rt) {
                ans = max(ans, count);
                return;
            }
            solve(rt->left, count + 1);
            solve(rt->right, count + 1);
        };
        solve(root, 0);
        return ans;
    }
};