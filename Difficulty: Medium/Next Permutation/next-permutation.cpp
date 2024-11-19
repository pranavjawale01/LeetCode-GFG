//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void reverse_arr(vector<int> &arr, int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
    int return_pivot(vector<int> arr) {
        int i = arr.size() - 2;
        while (i >= 0) {
            if (arr[i] < arr[i+1]) {
                return i;
            }
            i--;
        }
        return -1;
    }
    int find_greater(vector<int> arr, int pivot) {
        int index = arr.size() - 1;
        while (index > pivot) {
            if (arr[index] > arr[pivot]) {
                return index;
            }
            index--;
        }
        return -1;
    }
    void nextPermutation(vector<int>& arr) {
        // code here
        int pivot = return_pivot(arr);
        if (pivot == -1) {
            reverse_arr(arr, 0, arr.size() - 1);
            return;
        }
        int index = find_greater(arr, pivot);
        int tmp = arr[pivot];
        arr[pivot] = arr[index];
        arr[index] = tmp;
        reverse_arr(arr, pivot + 1, arr.size() - 1);
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
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends