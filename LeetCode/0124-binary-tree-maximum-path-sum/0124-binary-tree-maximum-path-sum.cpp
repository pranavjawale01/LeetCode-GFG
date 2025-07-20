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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        function<int(TreeNode*)> solve = [&](TreeNode* rt) {
            if (!rt) return 0;
            int l = max(0, solve(rt->left));
            int r = max(0, solve(rt->right));
            ans = max(ans, l + r + rt->val);
            return max(l, r) + rt->val;
        };
        solve(root);
        return ans;
    }
};