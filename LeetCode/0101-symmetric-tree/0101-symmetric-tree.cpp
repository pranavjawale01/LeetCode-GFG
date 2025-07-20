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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root); 
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            while (n--) {
                TreeNode *curr = q.front();
                q.pop();
                if (curr) {
                    temp.push_back(curr->val);
                    q.push(curr->left);
                    q.push(curr->right);
                } else {
                    temp.push_back(-200);
                }
            }
            int size = temp.size();
            for (int i = 0; i < size / 2; i++) {
                if (temp[i] != temp[size - i - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};







// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (!root) return true;
//         function<bool(TreeNode*, TreeNode*)> sym = [&](TreeNode *l, TreeNode *r) {
//             if (!l && !r) return true;
//             if (!l || !r || l->val != r->val) return false;
//             return sym(l->left, r->right) && sym(l->right, r->left);
//         };
//         return sym(root->left, root->right);
//     }
// };