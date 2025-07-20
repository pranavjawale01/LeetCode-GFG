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
class FindElements {
public:
    unordered_set<int> st;

    void bfs(TreeNode *root, int x) {
        queue<TreeNode*> q;
        root->val = x;
        q.push(root);
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            st.insert(temp->val);
            if (temp->left) {
                temp->left->val = 2 * temp->val + 1;
                q.push(temp->left);
            }
            if (temp->right) {
                temp->right->val = 2 * temp->val + 2;
                q.push(temp->right);
            }
        }
    }

    FindElements(TreeNode* root) {
        if (!root) return;
        bfs(root, 0);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */









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
// class FindElements {
// public:
//     unordered_set<int> st;

//     void dfs(TreeNode *root, int x) {
//         if (!root) return;
//         root->val = x;
//         st.insert(x);
//         dfs(root->left, 2 * x + 1);
//         dfs(root->right, 2 * x + 2);
//     }

//     FindElements(TreeNode* root) {
//         if (!root) return;
//         dfs(root, 0);
//     }
    
//     bool find(int target) {
//         return st.count(target);
//     }
// };

// /**
//  * Your FindElements object will be instantiated and called as such:
//  * FindElements* obj = new FindElements(root);
//  * bool param_1 = obj->find(target);
//  */