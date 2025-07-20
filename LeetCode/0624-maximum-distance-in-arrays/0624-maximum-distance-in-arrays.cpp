class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int minEl = arrays[0][0];
        int maxEl = arrays[0].back();

        for (int i = 1; i < arrays.size(); ++i) {
            auto& arr = arrays[i];
            int distMin = abs(arr[0] - maxEl);
            int distMax = abs(arr.back() - minEl);
            
            ans = max({ans, distMin, distMax});

            minEl = min(minEl, arr[0]);
            maxEl = max(maxEl, arr.back());
        }

        return ans;
    }
};