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
    vector<int> levelPrev;
    bool solve(TreeNode* root, int level) {
        if (!root) {
            return true;
        }
        if (level % 2 == root->val % 2) {
            return false;
        }
        if (level >= levelPrev.size()) {
            levelPrev.resize(level+1);
        }
        if (levelPrev[level] != 0) {
            if ((level % 2 == 0 && root->val <= levelPrev[level]) || (level % 2 != 0 && root->val >= levelPrev[level])) {
                return false;
            }
        }
        levelPrev[level] = root->val;
        return solve(root->left, level+1) && solve(root->right, level+1);
    }
    bool isEvenOddTree(TreeNode* root) {
        return solve(root, 0);
    }
};


// class Solution {
// public:
//     bool isEvenOddTree(TreeNode* root) {
//         queue<TreeNode*> q;
//         bool even = true;
//         q.push(root);
//         while (!q.empty()) {
//             int n = q.size();
//             int prev;
//             if (even) {
//                 prev = INT_MIN;
//             } else {
//                 prev = INT_MAX;
//             }
//             while (n--) {
//                 TreeNode* temp = q.front();
//                 if (temp->left) q.push(temp->left);
//                 if (temp->right) q.push(temp->right);
//                 q.pop();
//                 if (even && (temp->val % 2 == 0 || temp->val <= prev)) {
//                     return false;
//                 }
//                 if (!even && (temp->val % 2 != 0 || temp->val >= prev)) {
//                     return false;
//                 }
//                 prev = temp->val;
//             }
//             even = !even;
//         }
//         return true;
//     }
// };