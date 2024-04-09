class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int n = tickets.length;
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            q.add(i);
        }
        int time = 0;
        while (true) {
            if (tickets[k] == 0) {
                break;
            }
            int curr = q.poll();
            tickets[curr]--;
            time++;
            if (tickets[curr] > 0) {
                q.add(curr);
            }
        }
        return time;
    }
}