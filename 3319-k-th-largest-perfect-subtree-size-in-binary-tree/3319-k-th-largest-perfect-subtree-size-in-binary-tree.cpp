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
    vector<int> arr;
    pair<bool, pair<int, int>> solveTree(TreeNode *root) {
        if (!root) {
            return {true, {0, 0}};
        }
        pair<bool, pair<int, int>> left = solveTree(root->left);
        pair<bool, pair<int, int>> right = solveTree(root->right);
        bool leftBal = left.first;
        bool rightBal = right.first;
        int leftHt = left.second.first, leftSz = left.second.second;
        int rightHt = right.second.first, rightSz = right.second.second;
        if (leftBal && rightBal && leftHt == rightHt) {
            int len = leftSz + rightSz + 1;
            int ht = leftHt + 1;
            arr.push_back(len);
            return {true, {ht, len}};
        }
        return {false, {0, 0}};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        solveTree(root);
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        if (arr.size() >= k) {
            return arr[k - 1];
        }
        return -1;
    }
};