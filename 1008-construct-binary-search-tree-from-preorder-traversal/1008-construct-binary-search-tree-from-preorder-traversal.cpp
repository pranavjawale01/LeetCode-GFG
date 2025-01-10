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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        function<TreeNode*(int, int)> solve = [&](int s, int e) -> TreeNode* {
            if (s > e) return nullptr;
            TreeNode *root = new TreeNode(preorder[s]);
            int idx = s + 1;
            while (idx <= e && preorder[idx] < preorder[s]) {
                idx++;
            }
            root->left = solve(s + 1, idx - 1);
            root->right = solve(idx, e);
            return root;
        };
        return solve(0, preorder.size() - 1);
    }
};