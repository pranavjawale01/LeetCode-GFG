class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        int n = nums.size();
        int left = Integer.MAX_VALUE, right = Integer.MIN_VALUE;
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        
        for (int i = 0; i < n; i++) {
            minHeap.offer(new int[] {nums.get(i).get(0), i, 0});
            left = Math.min(left, nums.get(i).get(0));
            right = Math.max(right, nums.get(i).get(0));
        }

        int[] res = new int[] {left, right};

        while (true) {
            int[] minVal = minHeap.poll();
            int row = minVal[1], col = minVal[2];

            if (right - left < res[1] - res[0]) {
                res[0] = left;
                res[1] = right;
            }

            if (col + 1 == nums.get(row).size()) {
                break;
            }

            int nextVal = nums.get(row).get(col + 1);
            minHeap.offer(new int[] {nextVal, row, col + 1});
            right = Math.max(right, nextVal);
            left = minHeap.peek()[0];
        }

        return res;
    }
}