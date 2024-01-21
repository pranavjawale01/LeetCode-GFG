class Solution {
public:
    int recursive(vector<int>& nums, int amount, int house, int memory[]) {
        if (house > nums.size() - 1) {
            return 0;
        }
        if (memory[house] != -1) {
            return memory[house];
        }
        
        int selected = nums[house] + recursive(nums, amount, house + 2, memory);
        int notSelected = recursive(nums, amount, house + 1, memory);
        
        return memory[house] = max(selected, notSelected);
    }
    
    int rob(vector<int>& nums) {
        int memory[100];
        memset(memory, -1, sizeof(memory));
        int amount = 0, house = 0;
        return recursive(nums, amount, house, memory);
    }
};