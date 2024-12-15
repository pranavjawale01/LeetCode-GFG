class Solution {
    public double calGain(int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double) pass / total;
    }

    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<double[]> maxpq = new PriorityQueue<>((a, b) -> Double.compare(b[0], a[0]));
        for (int[] cls : classes) {
            maxpq.offer(new double[] {calGain(cls[0], cls[1]), cls[0], cls[1]});
        }
        while (extraStudents-- > 0) {
            double[] topEl = maxpq.poll();
            int pass = (int) topEl[1];
            int total = (int) topEl[2];
            maxpq.offer(new double[] {calGain(pass + 1, total + 1), pass + 1, total + 1});
        }
        double ans = 0;
        while (!maxpq.isEmpty()) {
            double[] topEl = maxpq.poll();
            int pass = (int) topEl[1];
            int total = (int) topEl[2];
            ans += (double) pass / total;
        }
        return ans / classes.length;
    }
}