class Solution {
    public int[][] updateMatrix(int[][] mat) {
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        int row = mat.length, col = mat[0].length;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    q.offer(new Pair<>(i, j));
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        int level = 1;
        int[][] dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        while (!q.isEmpty()) {
            int n = q.size();
            while (n-- > 0) {
                Pair<Integer, Integer> temp = q.poll();
                int x = temp.getKey();
                int y = temp.getValue();

                for (int[] dir : dirs) {
                    int i = x + dir[0];
                    int j = y + dir[1];
                    if (i < 0 || j < 0 || i >= row || j >= col || mat[i][j] != -1) {
                        continue;
                    }
                    mat[i][j] = level;
                    q.offer(new Pair<>(i, j));
                }
            }
            level++;
        }
        return mat;
    }
}