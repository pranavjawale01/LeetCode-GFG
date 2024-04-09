class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int maxVal = tickets[k];
        int ans = 0, n = tickets.length;
        for (int i = 0; i < n; i++) {
            if (tickets[i] >= maxVal) {
                if (i <= k) {
                    ans += maxVal;
                } else {
                    ans += maxVal - 1;
                }
            } else {
                ans += tickets[i];
            }
        }
        return ans;
    }
}

// class Solution {
//     public int timeRequiredToBuy(int[] tickets, int k) {
//         int n = tickets.length;
//         Queue<Integer> q = new LinkedList<>();
//         for (int i = 0; i < n; i++) {
//             q.add(i);
//         }
//         int time = 0;
//         while (true) {
//             if (tickets[k] == 0) {
//                 break;
//             }
//             int curr = q.poll();
//             tickets[curr]--;
//             time++;
//             if (tickets[curr] > 0) {
//                 q.add(curr);
//             }
//         }
//         return time;
//     }
// }