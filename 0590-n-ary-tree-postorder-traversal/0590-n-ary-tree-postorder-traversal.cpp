/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) return {};        
        stack<Node*> st;
        st.push(root);
        vector<int> ans;
        
        while (!st.empty()) {
            Node* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            
            for (Node* child : temp->children) {
                st.push(child);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};








// class Solution {
// public:
//     vector<int> ans;
//     void solve(Node *root) {
//         if (!root) {
//             return;
//         }
//         for (Node *child : root->children) {
//             solve(child);
//         }
//         ans.push_back(root->val);
//     }
//     vector<int> postorder(Node* root) {
//         solve(root);
//         return ans;
//     }
// };