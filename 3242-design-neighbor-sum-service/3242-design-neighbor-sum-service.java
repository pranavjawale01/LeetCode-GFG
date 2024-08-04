class neighborSum {

    private int[][] arr;
    private int row;
    private int col;
    private Map<Integer, int[]> mp;


    public neighborSum(int[][] grid) {
        arr = grid;
        row = grid.length;
        col = grid[0].length;
        mp = new HashMap<>();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                mp.put(grid[i][j], new int[]{i, j});
            }
        }
    }
    
    public int adjacentSum(int value) {
        if (!mp.containsKey(value)) {
            return 0;
        }
        int x = mp.get(value)[0];
        int y = mp.get(value)[1];
        int sum = 0;
        int[][] dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int[] d : dirs) {
            int a = d[0] + x;
            int b = d[1] + y;
            if (a >= 0 && a < row && b >= 0 && b < col) {
                sum += arr[a][b];
            }
        }
        return sum;
    }
    
    public int diagonalSum(int value) {
        if (!mp.containsKey(value)) {
            return 0;
        }
        int x = mp.get(value)[0];
        int y = mp.get(value)[1];
        int sum = 0;
        int[][] dirs = {{-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
        for (int[] d : dirs) {
            int a = d[0] + x;
            int b = d[1] + y;
            if (a >= 0 && a < row && b >= 0 && b < col) {
                sum += arr[a][b];
            }
        }
        return sum;
    }
}

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum obj = new neighborSum(grid);
 * int param_1 = obj.adjacentSum(value);
 * int param_2 = obj.diagonalSum(value);
 */