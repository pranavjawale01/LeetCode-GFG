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
    TreeNode *lowestCommonAncestor(TreeNode* root, int src, int dest) {
        if (!root) {
            return nullptr;
        }
        if (root->val == src || root->val == dest) {
            return root;
        }
        TreeNode *l = lowestCommonAncestor(root->left,  src, dest);
        TreeNode *r = lowestCommonAncestor(root->right, src, dest);
        if (l && r) {
            return root;
        }
        return l ? l : r;
    }

    bool findPath(TreeNode *LCA, int target, string &path) {
        if (!LCA) {
            return false;
        }
        if (LCA->val == target) {
            return true;
        }
        path.push_back('L');
        if (findPath(LCA->left, target, path)) {
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if (findPath(LCA->right, target, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *LCA = lowestCommonAncestor(root, startValue, destValue);
        string lcaToSrc = "";
        string lcaToDes = "";
        findPath(LCA, startValue, lcaToSrc);
        findPath(LCA, destValue, lcaToDes);
        string ans(lcaToSrc.size(), 'U');
        ans += lcaToDes;
        return ans;
    }
};