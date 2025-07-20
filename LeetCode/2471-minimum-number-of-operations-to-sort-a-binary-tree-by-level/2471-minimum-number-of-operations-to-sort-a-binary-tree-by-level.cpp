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
    int countMinSwap(vector<int> &arr) {
        int swaps = 0;
        vector<int> sorted(arr.begin(), arr.end());
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) mp[arr[i]] = i;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == sorted[i]) {
                continue;
            }
            int curridx = mp[sorted[i]];
            mp[arr[i]] = curridx;
            mp[arr[curridx]] = i;
            swap(arr[curridx], arr[i]);
            swaps++;
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> arr;
            while (n--) {
                TreeNode *temp = q.front();
                q.pop();
                arr.push_back(temp->val);
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            ans += countMinSwap(arr);
        }
        return ans;
    }
};