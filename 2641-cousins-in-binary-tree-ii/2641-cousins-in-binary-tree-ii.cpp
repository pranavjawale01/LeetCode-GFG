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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> levelSum;
        while (!q.empty()) {
            int currLvlSum = 0;
            int n = q.size();
            while (n--) {
                TreeNode *curr = q.front();
                q.pop();
                currLvlSum += curr->val;
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            levelSum.push_back(currLvlSum);
        }
        q.push(root);
        root->val = 0;
        int i = 1;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode *curr = q.front();
                q.pop();
                int siblingSum = curr->left ? curr->left->val : 0;
                siblingSum += curr->right ? curr->right->val : 0;
                if (curr->left) {
                    curr->left->val = levelSum[i] - siblingSum;
                    q.push(curr->left);
                } 
                if (curr->right) {
                    curr->right->val = levelSum[i] - siblingSum;
                    q.push(curr->right);
                }
            }
            i++;
        }
        return root;
    }
};