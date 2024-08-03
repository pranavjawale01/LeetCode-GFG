class Solution {
    public int minFlips(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int ans = 0;
        if (n % 2 == 1 && m % 2 == 1) {
            if (grid[n / 2][m / 2] == 1) {
                ans += 1;
            }
        }
        int[] shift = new int[3];
        if (n % 2 == 1) {
            int a = 0, b = m - 1;
            while (a < b) {
                int sum = grid[n/2][a] + grid[n/2][b];
                shift[sum] += 1;
                a++;
                b--;
            }
        }
        if (m % 2 == 1) {
            int a = 0, b = n - 1;
            while (a < b) {
                int sum = grid[a][m / 2] + grid[b][m/2];
                shift[sum] += 1;
                a++;
                b--;
            }
        }
        if (shift[2] % 2 == 1) {
            if (shift[1] > 0) {
                ans += shift[1];
            } else {
                ans += 2;
            }
        } else {
            ans += shift[1];
        }
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                int a = grid[i][j];
                int b = grid[n-1-i][j];
                int c = grid[i][m-1-j];
                int d = grid[n-1-i][m-1-j];
                int sum = a + b + c + d;
                if (sum != 0 && sum != 4) {
                    ans += Math.min(sum, 4 - sum);
                }
            }
        }
        return ans;
    }
}