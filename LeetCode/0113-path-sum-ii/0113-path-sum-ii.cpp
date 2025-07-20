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
    vector<vector<int>> ans;

    void solve(TreeNode* root, int targetSum, vector<int>& arr) {
        if (!root) {
            return;
        }

        arr.push_back(root->val);
        targetSum -= root->val;

        if (!root->left && !root->right) {
            if (targetSum == 0) {
                ans.push_back(arr);
            }
        } else {
            solve(root->left, targetSum, arr);
            solve(root->right, targetSum, arr);
        }

        arr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> arr;
        solve(root, targetSum, arr);
        return ans;
    }
};