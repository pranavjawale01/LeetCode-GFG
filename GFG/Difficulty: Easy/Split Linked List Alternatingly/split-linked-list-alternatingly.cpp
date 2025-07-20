//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        vector<Node*> ans(2, nullptr);
        Node* firstTail = nullptr;
        Node* secondTail = nullptr;
        
        Node* temp = head;
        int count = 0;

        while (temp) {
            if (count % 2 == 0) {
                if (ans[0] == nullptr) {
                    ans[0] = new Node(temp->data);
                    firstTail = ans[0];
                } else {
                    firstTail->next = new Node(temp->data);
                    firstTail = firstTail->next;
                }
            } else {
                if (ans[1] == nullptr) {
                    ans[1] = new Node(temp->data);
                    secondTail = ans[1];
                } else {
                    secondTail->next = new Node(temp->data);
                    secondTail = secondTail->next;
                }
            }
            count++;
            temp = temp->next;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends