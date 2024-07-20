class Solution {
    public int minChanges(int[] nums, int k) {
        int[] freq = new int[k + 1];
        List<Integer> vec = new ArrayList<>();
        int n = nums.length;
        
        for (int i = 0; i < n / 2; i++) {
            int diff = Math.abs(nums[i] - nums[n - i - 1]);
            freq[diff]++;
            int a = nums[i];
            int b = nums[n - i - 1];
            int threshold = Math.max(Math.max(a, b), k - Math.min(a, b));
            vec.add(threshold);
        }
        
        Collections.sort(vec);
        int ans = n / 2;
        n /= 2;
        
        for (int i = 0; i < k + 1; i++) {
            int rest = n - freq[i];
            int greater = lowerBound(vec, i);
            ans = Math.min(ans, rest + greater);
        }
        
        return ans;
    }
    
    private int lowerBound(List<Integer> vec, int target) {
        int left = 0;
        int right = vec.size();
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (vec.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
}