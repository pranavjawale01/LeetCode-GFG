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
    int findMaxDiff(TreeNode* root, int minV, int maxV) {
        if (root == nullptr) {
            return abs(minV - maxV);
        }
        minV = min(minV, root->val);
        maxV = max(maxV, root->val);
        int l = findMaxDiff(root->left, minV, maxV);
        int r = findMaxDiff(root->right, minV, maxV);
        return max(l, r);
    }
    int maxAncestorDiff(TreeNode* root) {
        return findMaxDiff(root, root->val, root->val);
    }
};

// class Solution {
// public:
//     int maxDiff;
//     void findMax (TreeNode* root, TreeNode* child) {
//         if (root == nullptr || child == nullptr) {
//             return;
//         }
//         maxDiff = max(maxDiff, abs(root->val - child->val));
//         findMax(root, child->left);
//         findMax(root, child->right);
//     }
//     void findMaxDiff(TreeNode* root) {
//         if (root == nullptr) {
//             return;
//         }
//         findMax (root, root->left);
//         findMax (root, root->right);
//         findMaxDiff (root->left);
//         findMaxDiff (root->right);
//     }
//     int maxAncestorDiff(TreeNode* root) {
//         maxDiff = -1;
//         findMaxDiff (root);
//         return maxDiff;
//     }
// };