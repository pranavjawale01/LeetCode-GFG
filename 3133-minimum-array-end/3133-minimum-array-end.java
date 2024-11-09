class Solution {
    public long minEnd(int n, int x) {
        n--;
        int[] xBits = new int[64];
        int[] nBits = new int[64];
        for (int i = 0; i < 32; i++) {
            xBits[i] = (x >> i) & 1;
            nBits[i] = (n >> i) & 1;
        }
        for (int i = 0, j = 0; i < 64 && j < 64; i++) {
            if (xBits[i] == 0) {
                xBits[i] = nBits[j++];
            }
        }
        long ans = 0;
        for (int i = 0; i < 64; i++) {
            ans |= ((long)xBits[i] << i);
        }
        return ans;
    }
}









// class Solution {
//     public long minEnd(int n, int x) {
//         long num = (long) x;
//         for (int i = 1; i < n; i++) {
//             num = (num + 1) | x;
//         }
//         return num;
//     }
// }