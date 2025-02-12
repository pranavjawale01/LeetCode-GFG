class Solution {
    public int sumOfDigit(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public int maximumSum(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        Arrays.sort(nums);
        int ans = -1;
        
        for (int num : nums) {
            int sum = sumOfDigit(num);
            if (map.containsKey(sum)) {
                ans = Math.max(ans, num + map.get(sum));
            }
            map.put(sum, num);
        }
        
        return ans;
    }
}