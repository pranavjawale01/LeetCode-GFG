class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {
        int row = maze.length, col = maze[0].length;
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int[][] dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int steps = 0;
        int x, y;
        while (!q.isEmpty()) {
            int n = q.size();
            steps++;
            for (int i = 0; i < n; i++) {
                int[] curr = q.poll();
                for (int[] dir : dirs) {
                    x = curr[0] + dir[0];
                    y = curr[1] + dir[1];
                    if (x < 0 || y < 0 || x >= row || y >= col || maze[x][y] == '+') {
                        continue;
                    }
                    if (x == 0 || y == 0 || x == row - 1 || y == col - 1) {
                        return steps;
                    }
                    maze[x][y] = '+';
                    q.offer(new int[]{x, y});
                }
            }
        }
        return -1;
    }
}