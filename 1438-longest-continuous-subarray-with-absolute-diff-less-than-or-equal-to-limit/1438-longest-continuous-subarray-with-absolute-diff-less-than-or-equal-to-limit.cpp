class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> st;
        int i = 0, j = 0;
        int maxlen = 0;
        while (j < n) {
            st.insert(nums[j]);
            while (*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[i]));
                i++;
            }
            maxlen = max(maxlen, j-i+1);
            j++;
        }
        return maxlen;
    }
};




// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, int limit) {
//         int n = nums.size();
//         priority_queue<pair<int, int>> mpq;
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lpq;

//         int i = 0, j = 0;
//         int maxlen = 0;
//         while (j < n) {
//             mpq.push({nums[j], j});
//             lpq.push({nums[j], j});

//             while (mpq.top().first - lpq.top().first > limit) {
//                 i = min(mpq.top().second, lpq.top().second) + 1;
//                 while (mpq.top().second < i) {
//                     mpq.pop();
//                 }
//                 while (lpq.top().second < i) {
//                     lpq.pop();
//                 }
//             }

//             maxlen = max(maxlen, j-i+1);
//             j++;
//         }
//         return maxlen;
//     }
// };