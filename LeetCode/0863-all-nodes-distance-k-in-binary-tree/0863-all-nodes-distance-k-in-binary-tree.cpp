/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
private:
    void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<int, vector<int>>& graph) {
        if (!node) return;
        if (parent) {
            graph[node->val].push_back(parent->val);
            graph[parent->val].push_back(node->val);
        }
        buildGraph(node->left, node, graph);
        buildGraph(node->right, node, graph);
    }

    vector<int> bfs(int target, int k, unordered_map<int, vector<int>>& graph) {
        vector<int> result;
        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(target);
        visited[target] = true;

        int level = 0;
        while (!q.empty()) {
            if (level == k) {
                while (!q.empty()) {
                    result.push_back(q.front());
                    q.pop();
                }
                break;
            }
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            level++;
        }

        return result;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> graph;
        buildGraph(root, nullptr, graph);

        return bfs(target->val, k, graph);
    }
};