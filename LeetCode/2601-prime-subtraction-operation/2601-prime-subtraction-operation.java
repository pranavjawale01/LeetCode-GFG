class Solution {
    public boolean[] prime = new boolean[1000];
    ArrayList<Integer> primeList = new ArrayList<>();
    
    void sieve() {
        Arrays.fill(prime, true);
        prime[0] = prime[1] = false;
        
        for (int i = 2; i * i < 1000; i++) {
            if (prime[i]) {
                for (int j = i * i; j < 1000; j += i) {
                    prime[j] = false;
                }
            }
        }
        
        for (int i = 2; i < 1000; i++) {
            if (prime[i]) {
                primeList.add(i);
            }
        }
    }
    
    public boolean primeSubOperation(int[] nums) {
        sieve();
        int n = nums.length;
        
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                continue;
            }
            
            boolean found = false;
            for (int p : primeList) {
                if (p >= nums[i]) break;
                
                if (nums[i] - p < nums[i + 1]) {
                    nums[i] -= p;
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                return false;
            }
        }
        
        return true;
    }
}