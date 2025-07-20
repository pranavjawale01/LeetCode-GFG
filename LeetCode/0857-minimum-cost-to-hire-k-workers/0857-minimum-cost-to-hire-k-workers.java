class Solution {
    public double mincostToHireWorkers(int[] quality, int[] minWage, int k) {
        int n = quality.length;

        double[][] workerRatio = new double[n][2];
        for (int worker = 0; worker < n; worker++) {
            workerRatio[worker][0] = (double) minWage[worker] / quality[worker];
            workerRatio[worker][1] = quality[worker];
        }

        Arrays.sort(workerRatio, Comparator.comparingDouble(a -> a[0]));

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        double sumQuality = 0;
        for (int i = 0; i < k; i++) {
            pq.add((int) workerRatio[i][1]);
            sumQuality += workerRatio[i][1];
        }

        double managerRatio = workerRatio[k - 1][0];
        double result = managerRatio * sumQuality;

        for (int manager = k; manager < n; manager++) {
            managerRatio = workerRatio[manager][0];

            pq.add((int) workerRatio[manager][1]);
            sumQuality += workerRatio[manager][1];

            if (pq.size() > k) {
                sumQuality -= pq.poll();
            }

            result = Math.min(result, managerRatio * sumQuality);
        }

        return result;
    }
}