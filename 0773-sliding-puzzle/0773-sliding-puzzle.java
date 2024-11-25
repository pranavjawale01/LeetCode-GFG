class Solution {
    public int slidingPuzzle(int[][] board) {
        StringBuilder start = new StringBuilder();
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                start.append(board[i][j]);
            }
        }
        String target = "123450";
        
        Queue<String> q = new LinkedList<>();
        q.offer(start.toString());
        
        Map<Integer, List<Integer>> mp = new HashMap<>();
        mp.put(0, Arrays.asList(1, 3));
        mp.put(1, Arrays.asList(0, 2, 4));
        mp.put(2, Arrays.asList(1, 5));
        mp.put(3, Arrays.asList(0, 4));
        mp.put(4, Arrays.asList(1, 3, 5));
        mp.put(5, Arrays.asList(2, 4));

        Set<String> vis = new HashSet<>();
        vis.add(start.toString());

        int level = 0;
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                String curr = q.poll();
                if (curr.equals(target)) return level;
                
                int idxOfZero = curr.indexOf('0');
                for (int swapIdx : mp.get(idxOfZero)) {
                    char[] newStateArr = curr.toCharArray();
                    char temp = newStateArr[idxOfZero];
                    newStateArr[idxOfZero] = newStateArr[swapIdx];
                    newStateArr[swapIdx] = temp;
                    String newState = new String(newStateArr);
                    
                    if (!vis.contains(newState)) {
                        q.offer(newState);
                        vis.add(newState);
                    }
                }
            }
            level++;
        }
        return -1;
    }
}