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
    void revinorder(TreeNode *root, int &sum) {
        if (!root) {
            return;
        }
        revinorder(root->right, sum);
        sum += root->val;
        root->val = sum;
        revinorder(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        revinorder(root, sum);
        return root;
    }
};





// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     vector<int> temp;
//     void inorder(TreeNode* root) {
//         if (!root) {
//             return;
//         }
//         inorder(root->left);
//         temp.push_back(root->val);
//         inorder(root->right);
//     }
//     int bs(int val, vector<int> &ans) {
//         int low = 0, high = ans.size() - 1;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (temp[mid] == val) {
//                 return ans[mid];
//             } else if (temp[mid] > val) {
//                 high = mid - 1;
//             } else {
//                 low = mid + 1;
//             }
//         }
//         return val;
//     }
//     void solve(TreeNode* root, vector<int> &ans) {
//         if (!root) {
//             return;
//         }
//         root->val = bs(root->val, ans);
//         solve(root->left, ans);
//         solve(root->right, ans);
//     }
//     TreeNode* bstToGst(TreeNode* root) {
//         inorder(root);
//         int n = temp.size();
//         vector<int> ans(n, 0);
//         ans[n-1] = temp[n-1];
//         for (int i = n-2; i >= 0; i--) {
//             ans[i] = temp[i] + ans[i+1];
//         }
//         solve(root, ans);
//         return root;
//     }
// };