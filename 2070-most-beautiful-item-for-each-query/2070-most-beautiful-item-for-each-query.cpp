class Solution {
public:
    int customBinarySearch(vector<vector<int>> &items, int queryPrice) {
        int l = 0, r = items.size() - 1;
        int mid;
        int maxBeauty = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (items[mid][0] > queryPrice) {
                r = mid - 1;
            } else {
                maxBeauty = max(maxBeauty, items[mid][1]);
                l = mid + 1;
            }
        }
        return maxBeauty;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();
        vector<int> ans(m);
        sort(items.begin(), items.end());
        int maxBeautySeen = items[0][1];
        for (int i = 1; i < n; i++) {
            maxBeautySeen = max(maxBeautySeen, items[i][1]);
            items[i][1] = maxBeautySeen;
        }
        for (int i = 0; i < m; i++) {
            int queryPrice = queries[i];
            ans[i] = customBinarySearch(items, queryPrice);
        }
        return ans;
    }
};