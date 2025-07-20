class Solution {
    int n;
    int[][] dp = new int[100001][3];

    public int binarySearch(List<int[]> events, int endTime) {
        int l = 0, r = n - 1, ans = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (events.get(mid)[0] > endTime) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    public int solve(List<int[]> events, int i, int count) {
        if (count == 2 || i >= n) {
            return 0;
        }
        if (dp[i][count] != -1) {
            return dp[i][count];
        }

        int nextValidEventIndex = binarySearch(events, events.get(i)[1]);
        int take = events.get(i)[2] + solve(events, nextValidEventIndex, count + 1);
        int notTake = solve(events, i + 1, count);
        return dp[i][count] = Math.max(take, notTake);
    }

    public int maxTwoEvents(int[][] events) {
        n = events.length;
        List<int[]> eventList = new ArrayList<>();
        for (int[] event : events) {
            eventList.add(event);
        }
        Collections.sort(eventList, (a, b) -> Integer.compare(a[0], b[0]));
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return solve(eventList, 0, 0);
    }
}