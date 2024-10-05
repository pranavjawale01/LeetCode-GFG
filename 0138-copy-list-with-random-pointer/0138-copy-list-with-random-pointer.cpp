/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }
        Node *curr = head;
        while (curr) {
            Node *copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        curr = head;
        Node *newHead = head->next;
        Node *copy = nullptr;
        while (curr) {
            copy = curr->next;
            curr->next = copy->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            curr = curr->next;
        }
        return newHead;
    }
};








// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         Node *temp = head;
//         unordered_map<Node*, Node*> mp;
//         while (temp) {
//             Node *newNode = new Node(temp->val);
//             mp[temp] = newNode;
//             temp = temp->next;
//         }
//         temp = head;
//         while (temp) {
//             Node *copyNode = mp[temp];
//             copyNode->next = mp[temp->next];
//             copyNode->random = mp[temp->random];
//             temp = temp->next;
//         }
//         return mp[head];
//     }
// };