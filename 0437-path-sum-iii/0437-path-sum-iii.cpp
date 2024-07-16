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
    int solve(TreeNode* root, long long curr, int target, std::unordered_map<long long, int> &mp) {
        if (!root) {
            return 0;
        }
        curr += root->val;
        int count = mp[curr - target];
        mp[curr]++;
        count += solve(root->left, curr, target, mp);
        count += solve(root->right, curr, target, mp);
        mp[curr]--;
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        mp[0] = 1;
        return solve(root, 0, targetSum, mp);
    }
};