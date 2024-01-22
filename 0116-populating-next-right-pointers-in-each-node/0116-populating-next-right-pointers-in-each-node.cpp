/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* cur = root;
        Node* nxt = root ? root->left : nullptr;
        
        while (cur && nxt) {
            cur->left->next = cur->right;
            
            if (cur->next) {
                cur->right->next = cur->next->left;
            }
            
            cur = cur->next;
            
            if (!cur) {
                cur = nxt;
                nxt = cur->left;
            }
        }
        
        return root;
    }
};