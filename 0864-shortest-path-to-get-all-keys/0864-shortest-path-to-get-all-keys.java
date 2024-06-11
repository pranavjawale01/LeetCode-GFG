class Solution {
    public int shortestPathAllKeys(String[] grid) {
        int m = grid.length;
        int n = grid[0].length();
        int totalKeys = 0;
        int startX = -1, startY = -1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char cell = grid[i].charAt(j);
                if (cell == '@') {
                    startX = i;
                    startY = j;
                } else if (Character.isLowerCase(cell)) {
                    totalKeys |= (1 << (cell - 'a'));
                }
            }
        }

        int[] dirx = {0, 0, 1, -1};
        int[] diry = {1, -1, 0, 0};

        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{startX, startY, 0});
        boolean[][][] vis = new boolean[m][n][1 << 6];
        vis[startX][startY][0] = true;

        int level = 0;

        while (!q.isEmpty()) {
            int size = q.size();
            while (size-- > 0) {
                int[] current = q.poll();
                int x = current[0], y = current[1], keys = current[2];

                if (keys == totalKeys) {
                    return level;
                }

                for (int i = 0; i < 4; ++i) {
                    int newx = x + dirx[i];
                    int newy = y + diry[i];

                    if (newx < 0 || newy < 0 || newx >= m || newy >= n) {
                        continue;
                    }

                    char cell = grid[newx].charAt(newy);
                    if (cell == '#') {
                        continue;
                    }

                    if (Character.isUpperCase(cell) && (keys & (1 << (cell - 'A'))) == 0) {
                        continue;
                    }

                    int newKeys = keys;
                    if (Character.isLowerCase(cell)) {
                        newKeys |= (1 << (cell - 'a'));
                    }

                    if (!vis[newx][newy][newKeys]) {
                        vis[newx][newy][newKeys] = true;
                        q.offer(new int[]{newx, newy, newKeys});
                    }
                }
            }
            ++level;
        }

        return -1;
    }
}