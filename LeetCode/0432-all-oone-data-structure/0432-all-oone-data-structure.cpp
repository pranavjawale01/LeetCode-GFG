class AllOne {
public:
    struct Node {
        int count;
        list<string> keys;
        Node *prev, *next;
        Node(int x) : count(x), prev(nullptr), next(nullptr) {}
    };

    unordered_map<string, Node*> mp;
    Node *head, *last;

    void addNode(Node *prevNode, int count) {
        Node *newNode = new Node(count);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }
        prevNode->next = newNode;
        if (prevNode == last) {
            last = newNode;
        }
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }
        if (last == node) {
            last = node->prev;
        }
        delete node;
    }

    AllOne() {
        head = new Node(0);
        last = head;
    }
    
    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            if (head->next == nullptr || head->next->count != 1) {
                addNode(head, 1);
            }
            head->next->keys.push_front(key);
            mp[key] = head->next;
        } else {
            Node *curr = mp[key];
            int currCount = curr->count;
            if (curr->next == nullptr || curr->next->count != currCount + 1) {
                addNode(curr, currCount + 1);
            }
            curr->next->keys.push_front(key);
            mp[key] = curr->next;
            curr->keys.remove(key);
            if (curr->keys.empty()) {
                removeNode(curr);
            }
        }
    }
    
    void dec(string key) {
        Node *curr = mp[key];
        int currCount = curr->count;
        if (currCount == 1) {
            mp.erase(key);
        } else {
            if (curr->prev->count != currCount - 1) {
                addNode(curr->prev, currCount - 1);
            }
            curr->prev->keys.push_front(key);
            mp[key] = curr->prev;
        }
        curr->keys.remove(key);
        if (curr->keys.empty()) {
            removeNode(curr);
        }
    }
    
    string getMaxKey() {
        if (last == head) {
            return "";
        }
        return last->keys.front();
    }
    
    string getMinKey() {
        if (head->next == nullptr) {
            return "";
        }
        return head->next->keys.front();
    }
};


/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */





//  class AllOne {
// public:
//     unordered_map<string, int> mp;
//     set<pair<int, string>> st;

//     AllOne() {
//         mp.clear();
//     }
    
//     void inc(string key) {
//         int n = mp[key];
//         mp[key]++;
//         st.erase({n, key});
//         st.insert({n+1, key});
//     }
    
//     void dec(string key) {
//         int n = mp[key];
//         mp[key]--;
//         st.erase({n, key});
//         if (mp[key] > 0) {
//             st.insert({n-1, key});
//         } else {
//             mp.erase(key);
//         }
//     }
    
//     string getMaxKey() {
//         if (!st.empty()) {
//             return st.rbegin()->second;
//         }
//         return "";
//     }
    
//     string getMinKey() {
//         if (!st.empty()) {
//             return st.begin()->second;
//         }
//         return "";
//     }
// };