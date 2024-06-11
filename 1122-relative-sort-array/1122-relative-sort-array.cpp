class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr2.size(); i++) {
            mp[arr2[i]] = i;
        }
        for (int &num : arr1) {
            if (!mp.count(num)) {
                mp[num] = 1e9;
            }
        }
        auto lambda = [&](int &num1, int &num2) {
            if (mp[num1] == mp[num2]) {
                return num1 < num2;
            }
            return mp[num1] < mp[num2];
        };
        sort(arr1.begin(), arr1.end(), lambda);
        return arr1;
    }
};



// class Solution {
// public:
//     vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
//         map<int, int> mp;
//         for (int x : arr1) {
//             mp[x]++;
//         }
//         vector<int> ans;
//         for (int x : arr2) {
//             while (mp[x] > 0) {
//                 ans.push_back(x);
//                 mp[x]--;
//             }
//             mp.erase(x);
//         }
//         for (auto& [key, value] : mp) {
//             while (value > 0) {
//                 ans.push_back(key);
//                 value--;
//             }
//         }
//         return ans;
//     }
// };