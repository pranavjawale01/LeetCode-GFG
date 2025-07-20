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
    TreeNode* solve(int l, int r, int &idx, vector<int>& inorder, vector<int>& postorder) {
        if (l > r) return nullptr;
        int val = postorder[idx--];
        TreeNode *ans = new TreeNode(val);
        int j = l;
        while (inorder[j] != val) j++;
        ans->right = solve(j+1, r, idx, inorder, postorder);
        ans->left = solve(l, j - 1, idx, inorder, postorder);
        return ans;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n - 1;
        return solve(0, n - 1, idx, inorder, postorder);
    }
};