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
    int result = 0;
    void solve(TreeNode* root, int count) {
        if (root == nullptr) {
            return;
        }
        count = (count ^ (1 << root->val));
        if (root->left == nullptr && root->right == nullptr) {
            if ((count & (count -1)) == 0) {
                result++;
            }
        }
        
        solve(root->left, count);
        solve(root->right, count);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root, 0);
        return result;
    }
};

// class Solution {
// public:
//     int result = 0;
//     void solve(TreeNode* root, vector<int>& count) {
//         if (root == nullptr) {
//             return;
//         }
//         count[root->val]++;
//         if (root->left == nullptr && root->right == nullptr) {
//             int freq = 0;
//             for (int  i = 0; i <= 9; i++) {
//                 if (count[i] % 2 != 0) {
//                     freq++;
//                 }
//             }
//             if (freq < 2) {
//                 result++;
//             }
//         }
        
//         solve(root->left, count);
//         solve(root->right, count);
        
//         count[root->val]--;
//     }
    
//     int pseudoPalindromicPaths (TreeNode* root) {
//         vector<int> count(10, 0);
//         solve(root, count);
//         return result;
//     }
// };

// // class Solution {
// // public:
// //     bool checkPalli(vector<int> input) {
// //         int n = input.size(), count = 0;
// //         for (int i = 0; i < n; i++) {
// //             if (input[i] % 2 != 0) {
// //                 count++;
// //             }
// //         }
// //         return count < 2;
// //     }

// //     void recursive(TreeNode* root, vector<vector<int>>& output, vector<int> temp) {
// //         if (root == nullptr) {
// //             return;
// //         }

// //         temp[root->val]++;

// //         if (root->left == nullptr && root->right == nullptr) {
// //             output.push_back(temp);
// //             return;
// //         }

// //         recursive(root->left, output, temp);
// //         recursive(root->right, output, temp);
// //     }



// //     int pseudoPalindromicPaths(TreeNode* root) {
// //         vector<vector<int>> output;
// //         vector<int> temp(10, 0);
// //         int count = 0;
// //         recursive(root, output, temp);
// //         int n = output.size();
// //         for (int i = 0; i < n; i++) {
// //             if (checkPalli(output[i])) {
// //                 count++;
// //             }
// //         }
// //         return count;
// //     }
// // };