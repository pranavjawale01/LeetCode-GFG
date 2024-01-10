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
    void makeGraph(unordered_map<int, vector<int>> &adj, int parent, TreeNode* curr) {
        if (curr == nullptr) {
            return;
        }
        if (parent != -1) {
            adj[curr->val].push_back(parent);
        }
        if (curr->left != nullptr) {
            adj[curr->val].push_back(curr->left->val);
        }
        if (curr->right != nullptr) {
            adj[curr->val].push_back(curr->right->val);
        }
        makeGraph(adj, curr->val, curr->left);
        makeGraph(adj, curr->val, curr->right);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<int, vector<int>> adj;
        makeGraph(adj, -1, root);
        
        queue<int> que;
        unordered_set<int> visited;
        
        que.push(start);
        visited.insert(start);
        
        int minutes = 0;
        
        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                int curr = que.front();
                que.pop();
                for (int &ngbr : adj[curr]) {
                    if (visited.find(ngbr) == visited.end()) {
                        que.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            minutes++;
        }
        return minutes - 1;
    }
};