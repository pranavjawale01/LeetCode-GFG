import java.util.PriorityQueue;

class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        int n = heights.length;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int i = 0;
        for (; i < n - 1; i++) {
            if (heights[i] >= heights[i + 1]) {
                continue;
            }
            int diff = heights[i + 1] - heights[i];
            if (diff <= bricks) {
                bricks -= diff;
                pq.add(diff);
            } else if (ladders > 0) {
                if (!pq.isEmpty()) {
                    int maxBricksPast = pq.peek();
                    if (maxBricksPast > diff) {
                        bricks += maxBricksPast;
                        pq.poll();
                        pq.add(diff);
                        bricks -= diff;
                    }
                }
                ladders--;
            } else {
                break;
            }
        }
        return i;
    }
};