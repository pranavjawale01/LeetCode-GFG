class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Map<Integer, Integer> lost_map = new HashMap<>();
        
        for (int i = 0; i < matches.length; i++) {
            lost_map.put(matches[i][1], lost_map.getOrDefault(matches[i][1],0)+1);
        }
        
        List<Integer> loss = new ArrayList<>();
        List<Integer> win = new ArrayList<>();
        
        for (int i = 0; i < matches.length; i++) {
            if (lost_map.get(matches[i][1]) == 1) {
                loss.add(matches[i][1]);
            }
            if (!lost_map.containsKey(matches[i][0])) {
                win.add(matches[i][0]);
                lost_map.put(matches[i][0], lost_map.getOrDefault(matches[i][0],0)+2);
            }
        }
        Collections.sort(loss);
        Collections.sort(win);
        return Arrays.asList(win, loss);
    }
}