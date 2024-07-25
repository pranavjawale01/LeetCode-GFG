//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};

bool help(Node* root, long long int up, long long int l) {
    if (root->data >= up || root->data <= l)
        return false;
    bool ans = true;
    if (root->left)
        ans = help(root->left, root->data, l);
    if (ans && root->right)
        ans = help(root->right, up, root->data);
    return ans;
}

bool isValidBST(Node* root) {
    return help(root, 3147483648, -3147483649);
}

int Height(Node* root) {

    if (root == NULL)
        return 0;

    int leftHeight = Height(root->left);

    int rightHight = Height(root->right);

    if (leftHeight == -1 || rightHight == -1 || abs(leftHeight - rightHight) > 1)
        return -1;

    return max(leftHeight, rightHight) + 1;
}

bool isBalanced(Node* root) {

    if (root == NULL)
        return true;

    if (Height(root) == -1)
        return false;
    return true;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

class Solution {
  public:
    Node* solve(int l, int r, vector<int>& nums) {
        if (l > r) {
            return nullptr;
        }
        int mid = (r - l) / 2 + l;
        Node* root = new Node(nums[mid]);
        root->left = solve(l, mid - 1, nums);
        root->right = solve(mid + 1, r, nums);
        return root;
    }

    Node* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return solve(0, n - 1, nums);
    }
};


//{ Driver Code Starts.
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

        Solution ob;
        Node* a = ob.sortedArrayToBST(arr);
        if (!isValidBST(a)) {
            cout << "false" << endl;
            return 0;
        }
        bool f = isBalanced(a);

        if (f)
            cout << "true";
        else
            cout << "false";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends