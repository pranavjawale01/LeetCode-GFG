class Solution {
    public int smallestChair(int[][] times, int targetFriend) {
        int n = times.length;
        Integer[] order = new Integer[n];
        for (int i = 0; i < n; i++) {
            order[i] = i;
        }
        
        Arrays.sort(order, (a, b) -> Integer.compare(times[a][0], times[b][0]));
        
        PriorityQueue<Integer> hpq = new PriorityQueue<>();
        PriorityQueue<int[]> lpq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        
        for (int i = 0; i < n; i++) {
            hpq.add(i);
        }
        
        for (int i : order) {
            int arrival = times[i][0], leave = times[i][1];
            
            while (!lpq.isEmpty() && lpq.peek()[0] <= arrival) {
                hpq.add(lpq.poll()[1]);
            }
            
            int seat = hpq.poll();
            
            if (i == targetFriend) return seat;
            
            lpq.add(new int[]{leave, seat});
        }
        
        return -1;
    }
}