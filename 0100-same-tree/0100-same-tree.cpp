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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }

        queue<TreeNode*> a,b;
        a.push(p);
        b.push(q);
        
        while (!a.empty() && !b.empty()) {
            TreeNode* temp1 = a.front();
            TreeNode* temp2 = b.front();
            a.pop();
            b.pop();

            if (temp1->val != temp2->val) {
                return false;
            }

            if (temp1->left && temp2->left) {
                a.push(temp1->left);
                b.push(temp2->left);
            } else if (temp1->left != nullptr || temp2->left != nullptr) {
                return false;
            }
            if (temp1->right && temp2->right) {
                a.push(temp1->right);
                b.push(temp2->right);
            } else if (temp1->right != nullptr || temp2->right != nullptr) {
                return false;
            }
        }
        return true;
    }
};

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {

//         if (p == nullptr && q == nullptr) {
//             return true;
//         }
    
//         if (p == nullptr || q == nullptr) {
//             return false;
//         }

//         return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//     }
// };