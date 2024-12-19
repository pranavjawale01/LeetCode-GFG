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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int maxWidth = 0;
        while (!q.empty()) {
            int n = q.size();
            int start = q.front().second;
            int end = q.back().second;
            maxWidth = max(maxWidth, end - start + 1);
            while (n--) {
                auto [node, idx] = q.front();
                q.pop();
                int normalisedidx = idx - start;
                if (node->left) q.push({node->left, 2 * normalisedidx + 1});
                if (node->right) q.push({node->right, 2 * normalisedidx + 2});
            }
        }
        return maxWidth;
    }
};