class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colorCount;
        unordered_map<int, int> prevColor;
        int n = queries.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];
            if (prevColor.count(ball)) {
                int prev = prevColor[ball];
                colorCount[prev]--;
                if (colorCount[prev] == 0) colorCount.erase(prev);   
            }
            prevColor[ball] = color;
            colorCount[color]++;
            res[i] = colorCount.size();
        }
        return res;
    }
};






// MLE
// class Solution {
// public:
//     vector<int> queryResults(int limit, vector<vector<int>>& queries) {
//         int n = queries.size();
//         unordered_map<int, int> mp;
//         vector<int> arr(limit+1, -1);
//         vector<int> res(n);
//         for (int i = 0; i < n; i++) {
//             int ball = queries[i][0];
//             int color = queries[i][1];
//             if (arr[ball] != -1) {
//                 int prevColor = arr[ball];
//                 mp[prevColor]--;
//                 if (mp[prevColor] == 0) {
//                     mp.erase(prevColor);
//                 }
//             }
//             arr[ball] = color;
//             mp[color]++;
//             res[i] = mp.size();
//         }
//         return res;
//     }
// };