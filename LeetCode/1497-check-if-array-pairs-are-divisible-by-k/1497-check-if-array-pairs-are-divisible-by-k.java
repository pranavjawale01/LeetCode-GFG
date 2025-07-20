class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] brr = new int[k];
        for (int x : arr) {
            int rem = ((x % k) + k) % k;
            brr[rem]++;
        }
        if (brr[0] % 2 == 1) {
            return false;
        }
        for (int rem = 1; rem <= k / 2; rem++) {
            int half = k - rem;
            if (brr[half] != brr[rem]) {
                return false;
            }
        }
        return true;
    }
}