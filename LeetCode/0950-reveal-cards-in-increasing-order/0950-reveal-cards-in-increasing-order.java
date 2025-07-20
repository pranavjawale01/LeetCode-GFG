class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int n = deck.length;
        Queue<Integer> q = new LinkedList<>();
        Arrays.sort(deck);
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            q.add(i);
        }
        for (int i = 0; i < n; i++) {
            int idx = q.poll();
            ans[idx] = deck[i];
            if (!q.isEmpty()) {
                q.add(q.poll());
            }
        }
        return ans;
    }
}

// class Solution {
//     public int[] deckRevealedIncreasing(int[] deck) {
//         int n = deck.length;
//         Arrays.sort(deck);
//         int[] ans = new int[n];
//         Arrays.fill(ans, 0);
//         boolean skip = false;
//         int i = 0, j = 0;
//         while (i < n) {
//             if (ans[j] == 0) {
//                 if (skip == false) {
//                     ans[j] = deck[i];
//                     i++;
//                 }
//                 skip = !skip;
//             }
//             j = (j + 1) % n;
//         }
//         return ans;
//     }
// }