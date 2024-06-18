class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        int n = profit.length;
        int m = worker.length;
        for (int i = 0; i < n; i++) {
            pq.add(new int[]{profit[i], difficulty[i]});
        }
        Arrays.sort(worker);
        int totalProfit = 0;
        int i = m - 1;
        while (!pq.isEmpty() && i >= 0) {
            if (pq.peek()[1] > worker[i]) {
                pq.poll();
            } else {
                totalProfit += pq.peek()[0];
                i--;
            }
        }
        return totalProfit;
    }
}