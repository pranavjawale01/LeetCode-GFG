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
    bool findPath(TreeNode *root, int target, string &path) {
        if (!root) {
            return false;
        }
        if (root->val == target) {
            return true;
        }
        path.push_back('L');
        if (findPath(root->left, target, path)) {
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if (findPath(root->right, target, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootToSrc = "", rootToDes = "";
        findPath(root, startValue, rootToSrc);
        findPath(root, destValue, rootToDes);

        int i = 0;
        while (i < rootToSrc.size() && i < rootToDes.size() && rootToSrc[i] == rootToDes[i]) {
            i++;
        }
        string ans(rootToSrc.size() - i, 'U');
        ans += rootToDes.substr(i);
        return ans;
    }
};









// class Solution {
// public:
//     TreeNode *lowestCommonAncestor(TreeNode* root, int src, int dest) {
//         if (!root) {
//             return nullptr;
//         }
//         if (root->val == src || root->val == dest) {
//             return root;
//         }
//         TreeNode *l = lowestCommonAncestor(root->left,  src, dest);
//         TreeNode *r = lowestCommonAncestor(root->right, src, dest);
//         if (l && r) {
//             return root;
//         }
//         return l ? l : r;
//     }

//     bool findPath(TreeNode *LCA, int target, string &path) {
//         if (!LCA) {
//             return false;
//         }
//         if (LCA->val == target) {
//             return true;
//         }
//         path.push_back('L');
//         if (findPath(LCA->left, target, path)) {
//             return true;
//         }
//         path.pop_back();
//         path.push_back('R');
//         if (findPath(LCA->right, target, path)) {
//             return true;
//         }
//         path.pop_back();
//         return false;
//     }

//     string getDirections(TreeNode* root, int startValue, int destValue) {
//         TreeNode *LCA = lowestCommonAncestor(root, startValue, destValue);
//         string lcaToSrc = "";
//         string lcaToDes = "";
//         findPath(LCA, startValue, lcaToSrc);
//         findPath(LCA, destValue, lcaToDes);
//         string ans(lcaToSrc.size(), 'U');
//         ans += lcaToDes;
//         return ans;
//     }
// };