typedef unsigned long long ll;
class Solution {
public:
    
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
    
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                result[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] > arr[i])
                    st.pop();
                
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]) 
                    st.pop();
                
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);
        
        
        ll sum = 0;
        int M = 1e9+7;
        for(int i = 0; i<n; i++) {
            ll d1 = i - NSL[i];
            
            ll d2 = NSR[i] - i; 
            
            ll total_ways_for_i_min = d1*d2;
            ll sum_i_in_total_ways  = arr[i] * (total_ways_for_i_min);
            
            sum  = (sum + sum_i_in_total_ways)%M;
        }
        
        return sum;
    }
};

// class Solution {
// public:
//     vector<int> getNSL(vector<int>& arr, int n) {
//         vector<int> result(n);
//         stack<int> st;
        
//         for (int i = 0; i < n; i++) {
//             while (!st.empty() && arr[st.top()] > arr[i]) {
//                 st.pop();
//             }
//             result[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }
        
//         return result;
//     }
    
//     vector<int> getNSR(vector<int>& arr, int n) {
//         vector<int> result(n);
//         stack<int> st;
        
//         for (int i = n - 1; i >= 0; i--) {
//             while (!st.empty() && arr[st.top()] > arr[i]) {
//                 st.pop();
//             }
//             result[i] = st.empty() ? n : st.top();
//             st.push(i);
//         }
        
//         return result;
//     }
    
//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();
        
//         vector<int> NSL = getNSL(arr, n);
//         vector<int> NSR = getNSR(arr, n);
        
//         long long sum = 0;
//         int N = 1e9 + 7;
        
//         for (int i = 0; i < n; i++) {
//             int ls = i - NSL[i];
//             int rs = NSR[i] - i;
            
//             int totalWays = (ls % N) * (rs % N) % N;
            
//             long long totalSum = arr[i] * totalWays;
            
//             sum = (sum + totalSum) % N;
//         }
        
//         return static_cast<int>(sum);
//     }
// };


// // Brute Force
// class Solution {
// public:
//     void subArray(vector<int>& arr, vector<vector<int>>& output) {
//         for (int i = 0; i < arr.size(); i++) {
//             vector<int> subarray;
//             for (int j = i; j < arr.size(); j++) {
//                 subarray.push_back(arr[j]);
//                 output.push_back(subarray);
//             }
//         }
//     }
    
//     int sumSubarrayMins(vector<int>& arr) {
//         const int modulo = 1000000007;
//         int result = 0;
//         vector<vector<int>> output;

//         subArray(arr, output);

//         for (int i = 0; i < output.size(); i++) {
//             result = (result + *min_element(output[i].begin(), output[i].end())) % modulo;
//         }

//         return result;
//     }
// };