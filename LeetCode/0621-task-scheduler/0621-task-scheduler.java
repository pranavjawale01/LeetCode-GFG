class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] mp = new int[26];
        for (char ch : tasks) {
            mp[ch - 'A']++;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>(26, Collections.reverseOrder());
        int time = 0;
        for (int i = 0; i < 26; i++) {
            if (mp[i] > 0) {
                pq.offer(mp[i]);
            }
        }
        while (!pq.isEmpty()) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int i = 1; i <= n + 1; i++) {
                if (!pq.isEmpty()) {
                    int freq = pq.poll();
                    freq--;
                    temp.add(freq);
                }
            }
            for (int f : temp) {
                if (f > 0) {
                    pq.offer(f);
                }
            }
            if (pq.isEmpty()) {
                time += temp.size();
            } else {
                time += n + 1;
            }
        }
        return time;
    }
}