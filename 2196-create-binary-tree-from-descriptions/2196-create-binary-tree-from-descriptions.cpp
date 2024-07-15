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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childSet;
        for (auto x : descriptions) {
            int p = x[0];
            int c = x[1];
            int l = x[2];
            if (mp.find(p) == mp.end()) {
                mp[p] = new TreeNode(p);
            }
            if (mp.find(c) == mp.end()) {
                mp[c] = new TreeNode(c);
            }
            if (l == 1) {
                mp[p]->left = mp[c];
            } else {
                mp[p]->right = mp[c];
            }
            childSet.insert(c);
        }
        for (auto x : descriptions) {
            int p = x[0];
            if (childSet.find(p) == childSet.end()) {
                return mp[p];
            }
        }
        return nullptr;
    }
};