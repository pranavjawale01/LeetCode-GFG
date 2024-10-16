class Solution {
    public String longestDiverseString(int a, int b, int c) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> y[0] - x[0]);
        if (a > 0) pq.offer(new int[]{a, 'a'});
        if (b > 0) pq.offer(new int[]{b, 'b'});
        if (c > 0) pq.offer(new int[]{c, 'c'});
        StringBuilder ans = new StringBuilder();
        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int freq = top[0];
            char ch = (char) top[1];
            if (ans.length() >= 2 && ans.charAt(ans.length() - 1) == ch && ans.charAt(ans.length() - 2) == ch) {
                if (pq.isEmpty()) break;
                int[] next = pq.poll();
                ans.append((char) next[1]);
                next[0]--;
                if (next[0] > 0) pq.offer(next);
            } else {
                ans.append(ch);
                freq--;
            }
            if (freq > 0) pq.offer(new int[]{freq, ch});
        }
        return ans.toString();
    }
}