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
    void solve(TreeNode* root, string &ans, string str) {
        if (root == nullptr) {
            return;
        }
        str = char('a' + root->val) + str;
        if (root->left == nullptr && root->right == nullptr) {
            if (ans.empty() || str <= ans) {
                ans = str;
            }
            return;
        }
        solve(root->left, ans, str);
        solve(root->right, ans, str);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "~";
        solve(root, ans, "");
        return ans;
    }
};