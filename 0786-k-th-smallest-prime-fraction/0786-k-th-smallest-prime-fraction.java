class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> Double.compare(a[0], b[0]));
        int n = arr.length;
        
        for (int i = 0; i < n; i++)
            pq.offer(new double[]{1.0 * arr[i] / arr[n - 1], (double) i, (double) (n - 1)});
        
        int smallest = 1;
        
        while (smallest < k) {
            double[] vec = pq.poll();
            int i = (int) vec[1];
            int j = (int) vec[2] - 1;
            
            pq.offer(new double[]{1.0 * arr[i] / arr[j], (double) i, (double) j});
            smallest++;
        }
        
        double[] vec = pq.poll();
        int i = (int) vec[1];
        int j = (int) vec[2];
        
        return new int[]{arr[i], arr[j]};
    }
}



// class Solution {
//     public int[] kthSmallestPrimeFraction(int[] arr, int k) {
//         PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> Double.compare(b[0], a[0]));
//         int n = arr.length;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 double div = (double) arr[i] / arr[j];
//                 pq.offer(new double[]{div, (double) arr[i], (double) arr[j]});
//                 if (pq.size() > k)
//                     pq.poll();
//             }
//         }

//         double[] vec = pq.peek();
//         return new int[]{(int) vec[1], (int) vec[2]};
//     }
// }



// class Solution {
//     public int[] kthSmallestPrimeFraction(int[] arr, int k) {
//         PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> Double.compare(b[0], a[0]));
//         int n = arr.length;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i != j) {
//                     pq.offer(new double[]{(double)arr[i] / arr[j], arr[i], arr[j]});
//                 }
//             }
//         }
//         while (--k > 0) {
//             pq.poll();
//         }
//         double[] fraction = pq.poll();
//         return new int[]{(int) fraction[2], (int) fraction[1]};
//     }
// }