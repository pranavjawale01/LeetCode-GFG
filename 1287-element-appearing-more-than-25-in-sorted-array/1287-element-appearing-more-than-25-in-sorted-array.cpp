class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> counter;
        for (int num : arr) {
            counter[num]++;
        }
        for (const auto& entry : counter) {
            if (entry.second > arr.size() / 4) {
                return entry.first;
            }
        }
        return 0;
    }
};