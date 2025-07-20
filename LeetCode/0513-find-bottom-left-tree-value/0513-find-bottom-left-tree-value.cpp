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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int value;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* temp = q.front();
                value = temp->val;
                q.pop();
                if (temp->right) {
                    q.push(temp->right);
                }
                if (temp->left) {
                    q.push(temp->left);
                }
            }
        }
        return value;
    }
};

// class Solution {
// public:
//     int findBottomLeftValue(TreeNode* root) {
//         queue<TreeNode*> q;
//         q.push(root);
//         int value;
//         while (!q.empty()) {
//             TreeNode* temp = q.front();
//             value = temp->val;
//             q.pop();
//             if (temp->right) {
//                 q.push(temp->right);
//             }
//             if (temp->left) {
//                 q.push(temp->left);
//             }
//         }
//         return value;
//     }
// };

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
//     int maxDepth;
//     int value;
//     void solve(TreeNode* root, int& depth) {
//         if (root == nullptr) {
//             return;
//         }
//         if (depth > maxDepth) {
//             maxDepth = depth;
//             value = root->val;
//         }
//         depth += 1;
//         solve(root->left, depth);
//         solve(root->right, depth);
//         depth -= 1;
//     }
//     int findBottomLeftValue(TreeNode* root) {
//         maxDepth = -1;
//         int depth;
//         solve(root, depth);
//         return value;
//     }
// };