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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        int ans = 0;
        while (!q.empty()) {
            int n = q.size();
            flag = true;
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                if (flag) {
                    flag = false;
                    ans += temp->val;
                }
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
                q.pop();
            }
        }
        return ans - root->val;
    }
};