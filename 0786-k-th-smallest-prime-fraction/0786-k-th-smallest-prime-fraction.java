class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> Double.compare(b[0], a[0]));
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    pq.offer(new double[]{(double)arr[i] / arr[j], arr[i], arr[j]});
                }
            }
        }
        while (--k > 0) {
            pq.poll();
        }
        double[] fraction = pq.poll();
        return new int[]{(int) fraction[2], (int) fraction[1]};
    }
}