class Solution {
    public int findChampion(int[][] grid) {
        Map<Integer, Integer> mp = new HashMap<>();
        int n = grid.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    mp.put(i, mp.getOrDefault(i, 0) + 1);
                } else {
                    mp.put(j, mp.getOrDefault(j, 0) + 1);
                }
            }
        }
        int team = -1;
        int freq = 0;
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            if (entry.getValue() > freq) {
                freq = entry.getValue();
                team = entry.getKey();
            }
        }
        return team;
    }
}