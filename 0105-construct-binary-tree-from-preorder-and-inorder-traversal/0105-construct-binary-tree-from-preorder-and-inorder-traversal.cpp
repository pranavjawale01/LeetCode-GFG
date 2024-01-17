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
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int start, int end, int &i) {
        if (start > end) {
            return nullptr;
        }
        int rootVal = preorder[i];
        int j = start;
        for (; j <= end; j++) {
            if (inorder[j] == rootVal) {
                break;
            }
        }
        i++;
        TreeNode* root = new TreeNode(rootVal);
        root->left = constructTree(preorder, inorder, start, j-1, i);
        root->right = constructTree(preorder, inorder, j+1, end, i);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int i = 0;
        return constructTree(preorder, inorder, 0, n-1, i);
    }
};