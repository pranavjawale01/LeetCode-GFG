class Solution {
public:
    // Boyer Moyer Algorithm
    vector<int> majorityElement(vector<int>& nums) {
        int element1 = 0, element2 = 0, count1 = 0, count2 = 0;
        for (int num : nums) {
            if (num == element1) {
                count1++;
            } else if (num == element2) {
                count2++;
            } else if (count1 == 0) {
                element1 = num;
                count1++;
            } else if (count2 == 0) {
                element2 = num;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1 = 0, count2 = 0;
        for (int num : nums) {
            if (element1 == num) {
                count1++;
            } else if (element2 == num) {
                count2++;
            }
        }
        if (count1 > nums.size() / 3) {
            ans.push_back(element1);
        }
        if (count2 > nums.size() / 3) {
            ans.push_back(element2);
        }
        return ans;
    }
};