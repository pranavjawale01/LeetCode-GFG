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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        if (!root) return ans;
        ans.push_back(root->val);
        while (!q.empty()) {
            int n = q.size();
            bool flag = false;
            int maxVal;
            while (n--) {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left) {
                    if (!flag) maxVal = temp->left->val;
                    flag = true;
                    q.push(temp->left);
                    maxVal = max(maxVal, temp->left->val);
                }
                if (temp->right) {
                    if (!flag) maxVal = temp->left->val;
                    flag = true;
                    q.push(temp->right);
                    maxVal = max(maxVal, temp->right->val);
                }
            }
            if (flag) {
                ans.push_back(maxVal);
            }
        }
        return ans;
    }
};