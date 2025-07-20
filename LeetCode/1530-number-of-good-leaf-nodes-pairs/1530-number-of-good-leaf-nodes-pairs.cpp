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
    vector<int> solve(TreeNode* root, int &distance, int &goodLeafNodes) {
        if (!root) {
            return {0};
        }
        if (!root->left && !root->right) {
            return {1};
        }
        vector<int> left = solve(root->left, distance, goodLeafNodes);
        vector<int> right= solve(root->right,distance, goodLeafNodes);

        for (int &l : left) {
            for (int &r : right) {
                if (l != 0 && r != 0 && l + r <= distance) {
                    goodLeafNodes++;
                }
            }
        }

        vector<int> curr;
        for (int &l : left) {
            if (l != 0 && l + 1 <= distance)  {
                curr.push_back(l+1);
            }
        }
        for (int &r : right) {
            if (r != 0 && r + 1 <= distance)  {
                curr.push_back(r+1);
            }
        }
        return curr;
    }
    int countPairs(TreeNode* root, int distance) {
        int goodLeafNodes = 0;
        solve(root, distance, goodLeafNodes);
        return goodLeafNodes;
    }
};








// class Solution {
// public:
//     void makeGraph(TreeNode *root, TreeNode *prev, unordered_map<TreeNode*, vector<TreeNode*>> &mp, unordered_set<TreeNode*> &st) {
//         if (root == nullptr) {
//             return;
//         }
//         if (!root->left && !root->right) {
//             st.insert(root);
//         }
//         if (prev) {
//             mp[root].push_back(prev);
//             mp[prev].push_back(root);
//         }
//         makeGraph(root->left, root, mp, st);
//         makeGraph(root->right,root, mp, st);
//     }

//     int countPairs(TreeNode* root, int distance) {
//         unordered_map<TreeNode*, vector<TreeNode*>> mp;
//         unordered_set<TreeNode*> st;
//         makeGraph(root, nullptr, mp, st);
//         int count = 0;
//         for (auto &leaf : st) {
//             queue<TreeNode*> q;
//             unordered_set<TreeNode*> vis;
//             q.push(leaf);
//             vis.insert(leaf);
//             for (int level = 0; level <= distance; level++) {
//                 int size = q.size();
//                 while (size--) {
//                     TreeNode *curr = q.front();
//                     q.pop();
//                     if (curr != leaf && st.count(curr)) {
//                         count++;
//                     }
//                     for (auto &x : mp[curr]) {
//                         if (!vis.count(x)) {
//                             q.push(x);
//                             vis.insert(x);
//                         }
//                     }
//                 }
//             }
//         }
//         return count / 2;
//     }
// };