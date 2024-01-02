class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int arr[201] = {0};
        int maxelement = 0;

        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]]++;
            maxelement = max(maxelement, arr[nums[i]]);
        }

        vector<vector<int>> res;
        int i = 1;

        while (i <= maxelement) {
            vector<int> list;
            for (int j = 0; j < 201; j++) {
                if (arr[j] >= i) {
                    list.push_back(j);
                }
            }
            if (!list.empty()) {
                res.push_back(list);
            }
            i++;
        }
        return res;
    }
};