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
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int preStart, int postStart, int size) {
        if (size == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        if (size == 1) return root;
        int leftRootVal = preorder[preStart + 1];
        int leftSize = 0;
        for (int i = postStart; i < postStart + size; ++i) {
            if (postorder[i] == leftRootVal) {
                leftSize = i - postStart + 1;
                break;
            }
        }
        root->left = solve(preorder, postorder, preStart + 1, postStart, leftSize);
        root->right = solve(preorder, postorder, preStart + 1 + leftSize, postStart + leftSize, size - 1 - leftSize);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return solve(preorder, postorder, 0, 0, preorder.size());
    }
};