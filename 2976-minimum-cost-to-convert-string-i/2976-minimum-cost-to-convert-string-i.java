class Solution {
    private void floydWarshall(long[][] arr) {
        long val = Integer.MAX_VALUE;
        for (int via = 0; via < 26; via++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (arr[i][via] < val && arr[via][j] < val) {
                        arr[i][j] = Math.min(arr[i][j], arr[i][via] + arr[via][j]);
                    }
                }
            }
        }
    }
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        long[][] arr = new long[26][26];
        for (int i = 0; i < 26; i++) {
            Arrays.fill(arr[i], Integer.MAX_VALUE);
        }
        int n = original.length;
        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            arr[u][v] = Math.min((long)(cost[i]), arr[u][v]);
        }
        for (int i = 0; i < 26; i++) {
            arr[i][i] = 0;
        }
        floydWarshall(arr);
        n = target.length();
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int u = source.charAt(i) - 'a';
            int v = target.charAt(i) - 'a';
            if (arr[u][v] == Integer.MAX_VALUE) {
                return -1;
            }
            ans += arr[u][v];
        }
        return ans;
    }
}