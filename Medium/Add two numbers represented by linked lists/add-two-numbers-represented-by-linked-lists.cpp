//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    Node* reverse(Node* head) {
        if (!head || !head->next) {
            return head;
        }
        Node* prev = nullptr, *curr = head, *nxt = nullptr;
        while (curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    Node* addNum(Node* n1, Node* n2) {
        if (!n1) {
            return n2;
        }
        if (!n2) {
            return n1;
        }
        Node* head = n1;
        Node* tail;
        int carry = 0;
        while (n1 && n2) {
            n1->data += carry + n2->data;
            carry = n1->data / 10;
            n1->data %= 10;
            tail = n1;
            n1 = n1->next;
            n2 = n2->next;
        }
        if (n2) {
            tail->next = n2;
            n1 = n2;
        }
        while (n1) {
            n1->data += carry;
            carry = n1->data / 10;
            n1->data %= 10;
            tail = n1;
            n1 = n1->next;
        }
        n1 = tail;
        while (carry) {
            n1->next = new Node(carry);
            carry = n1->next->data / 10;
            n1->next->data %= 10;
            n1 = n1->next;
        }
        return head;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
        if (!num1) {
            return num2;
        } 
        if (!num2) {
            return num1;
        }
        while (num1->next && num1->data == 0) {
            num1 = num1->next;
        }
        while (num2->next && num2->data == 0) {
            num2 = num2->next;
        }
        num1 = reverse(num1);
        num2 = reverse(num2);
        return reverse(addNum(num1, num2));
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends