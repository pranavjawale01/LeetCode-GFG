class Solution {
    public int threeSumMulti(int[] arr, int target) {
        Arrays.sort(arr);
        int n = arr.length;
        long count = 0;
        int mod = 1000000007;

        for (int i = 0; i < n - 2; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == target) {
                    int left = 1, right = 1;
                    while (j < k && arr[j] == arr[j + 1]) {
                        left++;
                        j++;
                    }
                    while (k > j && arr[k] == arr[k - 1]) {
                        right++;
                        k--;
                    }
                    if (j == k) {
                        long temp = (left * (left - 1)) / 2;
                        count = (count + temp) % mod;
                    } else {
                        count = (count + left * right) % mod;
                    }
                    j++;
                    k--;
                } else if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return (int) count;
    }
}