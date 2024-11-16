class Solution {
    private void reverse(char[] arr, int left, int right) {
        while (left < right) {
            char temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    public int nextGreaterElement(int n) {
        char[] digits = Integer.toString(n).toCharArray();
        int len = digits.length;
        int i = len - 2;
        while (i >= 0 && digits[i] >= digits[i + 1]) {
            i--;
        }
        if (i < 0) return -1;
        int j = len - 1;
        while (j >= 0 && digits[j] <= digits[i]) {
            j--;
        }
        char temp = digits[i];
        digits[i] = digits[j];
        digits[j] = temp;
        reverse(digits, i + 1, len - 1);
        long ans = Long.parseLong(new String(digits));
        return (ans > Integer.MAX_VALUE) ? -1 : (int) ans;
    }
}