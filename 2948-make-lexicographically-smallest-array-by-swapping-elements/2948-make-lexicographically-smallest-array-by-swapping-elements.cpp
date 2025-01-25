class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        int groupNum = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[vec[0]] = groupNum;
        unordered_map<int, list<int>> groupToList;
        groupToList[groupNum].push_back(vec[0]);
        for (int i = 1; i < n; i++) {
            if (abs(vec[i] - vec[i-1]) > limit) {
                groupNum++;
            }
            numToGroup[vec[i]] = groupNum;
            groupToList[groupNum].push_back(vec[i]);
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int group = numToGroup[num];
            res[i] = *groupToList[group].begin();
            groupToList[group].pop_front();
        }
        return res;
    }
};








// TLE
// class Solution {
// public:
//     vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             while (true) {
//                 int smallVal = nums[i];
//                 int idx = -1;
//                 for (int j = i + 1; j < n; j++) {
//                     if (abs(nums[i] - nums[j]) <= limit) {
//                         if (nums[j] < smallVal) {
//                             smallVal = nums[j];
//                             idx = j;
//                         }
//                     }
//                 }
//                 if (idx != -1) {
//                     swap(nums[i], nums[idx]);
//                 } else {
//                     break;
//                 }
//             }
//         }
//         return nums;
//     }
// };