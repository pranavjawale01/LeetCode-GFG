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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> lvlNodes;
            while (n--) {
                TreeNode *temp = q.front();
                q.pop();
                lvlNodes.push_back(temp);
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            if (level % 2 == 1) {
                int l = 0, r = lvlNodes.size() - 1;
                while (l < r) {
                    int temp = lvlNodes[l]->val;
                    lvlNodes[l]->val = lvlNodes[r]->val;
                    lvlNodes[r]->val = temp;
                    l++;
                    r--;
                }
            }
            level++;
        }
        return root;
    }
};







// class Solution {
// public:
//     void solve(TreeNode *l, TreeNode *r, int lvl) {
//         if (!l || !r) {
//             return;
//         }
//         if (lvl % 2 == 1) {
//             int temp = l->val;
//             l->val = r->val;
//             r->val = temp;
//         }
//         solve(l->left, r->right, lvl + 1);
//         solve(l->right, r->left, lvl + 1);
//     }
//     TreeNode* reverseOddLevels(TreeNode* root) {
//         solve(root->left, root->right, 1);
//         return root;
//     }
// };