//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    bool help(string A, vector<string> &B, int index) {
        if (index == A.length()) {
            return true;
        }
        string temp = "";
        bool a = false;
        for (int i = index; i < A.length(); i++) {
            temp += A[i];
            for (int j = 0; j < B.size(); j++) {
                if (B[j] == temp) {
                    a = a | help(A, B, i+1);
                    break;
                }
            }
        }
        return a;
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        return help(s, dictionary, 0);
    }
};

// class Solution
// {
// public:
//     bool help(string A, unordered_set<string> &mm, int index) {
//         if (index == A.length()) {
//             return true;
//         }
//         bool a = false;
//         string temp = "";
//         for (int i = index; i < A.length(); i++) {
//             temp += A[i];
//             if (mm.find(temp) != mm.end()) {
//                 a = a | help(A, mm, i+1);
//             }
//         }
//         return a;
//     }
//     int wordBreak(int n, string s, vector<string> &dictionary) {
//         unordered_set<string> mm;
//         for (auto x : dictionary) {
//             mm.insert(x);
//         }
//         return help(s, mm, 0);
//     }
// };

// //IF string with name continuation does not exist then it will work fine
// //(Greedy Approach)
// class Solution {
// public:
//     int wordBreak(int n, string s, vector<string> &dictionary) {
//         unordered_set<string> dict(dictionary.begin(), dictionary.end());
//         int left = 0;
//         string ans = "";
//         for (int right = 0; right < n; right++) {
//             string temp = s.substr(left, right - left + 1);
//             if (dict.find(temp) != dict.end()) {
//                 left++;
//                 right=left;
//                 ans += temp;
//             } 
//         }
//         return s == ans;
//     }
// };

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends