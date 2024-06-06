class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        int n = hand.length;
        if (n % groupSize != 0) {
            return false;
        }
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        for (int x : hand) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        while (!mp.isEmpty()) {
            int curr = mp.firstKey();
            for (int i = 0; i < groupSize; i++) {
                if (mp.getOrDefault(curr + i, 0) == 0) {
                    return false;
                }
                mp.put(curr + i, mp.get(curr + i) - 1);
                if (mp.get(curr + i) == 0) {
                    mp.remove(curr + i);
                }
            }
        }
        return true;
    }
}