class Solution {
    public String getPermutation(int n, int k) {
        StringBuilder result = new StringBuilder();
        List<Integer> nums = new ArrayList<>();

        for (int i = 1; i <= n; ++i) {
            nums.add(i);
        }

        while (n > 0) {
            int fact = 1;
            for (int i = 1; i < n; ++i) {
                fact *= i;
            }

            int index = (k - 1) / fact;
            k = (k - 1) % fact + 1;

            result.append(nums.get(index));
            nums.remove(index);

            --n;
        }

        return result.toString();
    }
}