class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int n = profit.length;
        int m = worker.length;
        List<int[]> jobs = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            jobs.add(new int[] {difficulty[i], profit[i]});
        }
        
        Collections.sort(jobs, (a, b) -> a[0] - b[0]);
        Arrays.sort(worker);
        
        int totalProfit = 0;
        int j = 0;
        int maxProfit = 0;
        
        for (int i = 0; i < m; i++) {
            while (j < n && worker[i] >= jobs.get(j)[0]) {
                maxProfit = Math.max(maxProfit, jobs.get(j)[1]);
                j++;
            }
            totalProfit += maxProfit;
        }
        
        return totalProfit;
    }
}




// class Solution {
//     public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
//         int n = profit.length;
//         int m = worker.length;
//         List<Pair<Integer, Integer>> lis = new ArrayList<>();
//         for (int i = 0; i < n; i++) {
//             lis.add(new Pair<>(difficulty[i], profit[i]));
//         }
//         lis.sort((a, b) -> a.getKey() - b.getKey());
//         for (int i = 1; i < lis.size(); i++) {
//             lis.set(i, new Pair<>(lis.get(i).getKey(), Math.max(lis.get(i).getValue(), lis.get(i - 1).getValue())));
//         }
//         int totalProfit = 0;
//         for (int i = 0; i < m; i++) {
//             int level = worker[i];
//             int l = 0, r = lis.size() - 1;
//             int maxProfit = 0;
//             while (l <= r) {
//                 int mid = l + (r - l) / 2;
//                 if (lis.get(mid).getKey() <= level) {
//                     maxProfit = Math.max(maxProfit, lis.get(mid).getValue());
//                     l = mid + 1;
//                 } else {
//                     r = mid - 1;
//                 }
//             }
//             totalProfit += maxProfit;
//         }
//         return totalProfit;
//     }
// }




// class Solution {
//     public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
//         PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
//         int n = profit.length;
//         int m = worker.length;
//         for (int i = 0; i < n; i++) {
//             pq.add(new int[]{profit[i], difficulty[i]});
//         }
//         Arrays.sort(worker);
//         int totalProfit = 0;
//         int i = m - 1;
//         while (!pq.isEmpty() && i >= 0) {
//             if (pq.peek()[1] > worker[i]) {
//                 pq.poll();
//             } else {
//                 totalProfit += pq.peek()[0];
//                 i--;
//             }
//         }
//         return totalProfit;
//     }
// }