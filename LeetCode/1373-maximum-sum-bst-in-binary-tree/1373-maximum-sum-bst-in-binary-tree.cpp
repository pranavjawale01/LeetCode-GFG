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
    int res = 0;
    
    vector<int> solve(TreeNode *root) {
        if (!root) return {INT_MAX, INT_MIN, 0};
        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);
        if (left[1] >= root->val || right[0] <= root->val) {
            return {INT_MIN, INT_MAX, 0};
        }
        int sum = left[2] + right[2] + root->val;
        res = max(res, sum);
        return {min(root->val, left[0]), max(root->val, right[1]), sum};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        if (res < 0) return 0;
        return res;
    }
};