class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;

        for(int &x : arr) {
            mp[x]++;
        }

        vector<int> freqCount(n+1);
        //freqCount[i] = number of elements (types) having frequency = i

        int uniqueTypes = mp.size();

        for(auto &it : mp) {
            int freq = it.second;
            freqCount[freq]++;
        }


        for(int freq = 1; freq <= n; freq++) {

            int typesICanDelete = min(k/freq, freqCount[freq]);

            k -= (typesICanDelete * freq);

            uniqueTypes -= typesICanDelete;

            if(k <= freq) {
                return uniqueTypes;
            }
        }

        return 0;


    }
};

// class Solution {
// public:
//     int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
//         unordered_map<int, int> mp;
//         for (int &a : arr) {
//             mp[a]++;
//         }

//         priority_queue<int, vector<int>, greater<int>> pq;

//         for (auto &it : mp) {
//             pq.push(it.second);
//         }

//         while (!pq.empty()) {
//             k -= pq.top();
//             if (k < 0) {
//                 return pq.size();
//             }
//             pq.pop();
//         }

//         return 0;
//     }
// };

// // class Solution {
// // public:
// //     int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
// //         unordered_map<int, int> mp;
// //         for (int &ar : arr) {
// //             mp[ar]++;
// //         }
// //         vector<int> freq;
// //         for (auto& it : mp) {
// //             freq.push_back(it.second);
// //         }
// //         sort(freq.begin(), freq.end());
// //         for (int i = 0; i < freq.size(); i++) {
// //             k -= freq[i];
// //             if (k < 0) {
// //                 return freq.size() - i;
// //             }
// //         }
// //         return 0;
// //     }
// // };

// // // class Solution {
// // // public:
// // //     int minCount = INT_MAX;
// // //     void solve(vector<int>& arr, int k, int n, int start, int end) {
// // //         if (end >= n) {
// // //             return;
// // //         }
// // //         int uniqueCount = 0;
// // //         unordered_map<int, int> mp;
// // //         for (int i = 0; i < n; i++) {
// // //             if (i < start || i > end) {
// // //                 mp[arr[i]]++;
// // //             }
// // //         }
// // //         for (auto& pair : mp) {
// // //             if (pair.second > 0) {
// // //                 uniqueCount++;
// // //             }
// // //         }
// // //         minCount = min(minCount, uniqueCount);
// // //         solve(arr, k, n, start+k, end+k);
// // //     }
// // //     int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
// // //         int n = arr.size();
// // //         if (n == 1 && k == 0) {
// // //             return 1;
// // //         } else if (n == k) {
// // //             return 0;
// // //         }
// // //         sort(arr.begin(), arr.end());
// // //         solve(arr, k, n, 0, k);
// // //         return minCount;
// // //     }
// // // };