/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        
        mp.clear();
        Node* clone_node = new Node(node->val);
        mp[node] = clone_node;
        
        queue<Node*> q;
        q.push(node);
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            Node* clone_current = mp[current];
            
            for (Node* neighbor : current->neighbors) {
                if (mp.find(neighbor) == mp.end()) {
                    Node* clone_neighbor = new Node(neighbor->val);
                    mp[neighbor] = clone_neighbor;
                    clone_current->neighbors.push_back(clone_neighbor);
                    q.push(neighbor);
                } else {
                    clone_current->neighbors.push_back(mp[neighbor]);
                }
            }
        }
        
        return clone_node;
    }
};


// class Solution {
// public:
//     unordered_map<Node*, Node*> mp;
//     void DFS(Node* node, Node* clone_node) {
//         for (Node* n : node->neighbors) {
//             if (mp.find(n) == mp.end()) {
//                 Node* clone = new Node(n->val);
//                 mp[n] = clone;
//                 clone_node->neighbors.push_back(clone);
//                 DFS(n, clone);
//             } else {
//                 clone_node->neighbors.push_back(mp[n]);
//             }
//         }
//     }
//     Node* cloneGraph(Node* node) {
//         if (!node) {
//             return nullptr;
//         }
//         mp.clear();
//         Node* clone_node = new Node(node->val);
//         mp[node] = clone_node;
//         DFS(node, clone_node);
//         return clone_node;
//     }
// };