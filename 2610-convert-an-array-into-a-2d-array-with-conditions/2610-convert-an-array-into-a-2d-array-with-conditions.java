public class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        int[] count = new int[201];
        int maxElement = 0;
        
        for (int i = 0; i < nums.length; i++) {
            count[nums[i]]++;
            maxElement = Math.max(maxElement, count[nums[i]]);
        }
        
        int i = 1;
        List<List<Integer>> result = new ArrayList<>();

        while (i <= maxElement) {
            List<Integer> temp = new ArrayList<>();
            
            for (int j = 0; j < 201; j++) {
                if (count[j] >= i) {
                    temp.add(j);
                }
            }
            
            if (!temp.isEmpty()) {
                result.add(temp);
            }
            
            i++;
        }
        
        return result;
    }
}