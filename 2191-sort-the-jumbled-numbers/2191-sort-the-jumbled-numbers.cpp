class Solution {
public:
    int mapValue(int num, const vector<int>& mapping) {
        if (num == 0) return mapping[0];
        int mappedVal = 0, place = 1;
        while (num > 0) {
            mappedVal += mapping[num % 10] * place;
            num /= 10;
            place *= 10;
        }
        return mappedVal;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> mappedNums;
        
        for (int num : nums) {
            mappedNums.push_back({mapValue(num, mapping), num});
        }
        
        stable_sort(mappedNums.begin(), mappedNums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });
        
        vector<int> sortedNums;
        for (const auto& p : mappedNums) {
            sortedNums.push_back(p.second);
        }
        
        return sortedNums;
    }
};