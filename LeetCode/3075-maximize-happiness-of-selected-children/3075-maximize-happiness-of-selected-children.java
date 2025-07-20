class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        long result = 0;
        int count = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int hap : happiness) {
            pq.offer(hap);
        }

        for (int i = 0; i < k; i++) {
            int hap = pq.poll();
            result += Math.max(hap - count, 0);
            count++;
        }

        return result;
    }
}


// class Solution {
//     public long maximumHappinessSum(int[] happiness, int k) {
//         Arrays.sort(happiness);
//         long sum = 0;
//         int n = happiness.length;
//         for (int i = n - 1, j = 0; i >=  n - k; i--, j++) {
//             if (happiness[i] - j > 0) {
//                 sum += happiness[i] - j;
//             } else {
//                 return sum;
//             }
//         }
//         return sum;
//     }
// }