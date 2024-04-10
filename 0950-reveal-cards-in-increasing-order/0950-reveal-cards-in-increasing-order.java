class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int n = deck.length;
        Arrays.sort(deck);
        int[] ans = new int[n];
        Arrays.fill(ans, 0);
        boolean skip = false;
        int i = 0, j = 0;
        while (i < n) {
            if (ans[j] == 0) {
                if (skip == false) {
                    ans[j] = deck[i];
                    i++;
                }
                skip = !skip;
            }
            j = (j + 1) % n;
        }
        return ans;
    }
}