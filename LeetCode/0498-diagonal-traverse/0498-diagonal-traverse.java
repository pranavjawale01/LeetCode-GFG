class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        Map<Integer, ArrayList<Integer>> mp = new HashMap<>();
        int m = mat.length, n = mat[0].length;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int diagonalSum = i + j;
                mp.putIfAbsent(diagonalSum, new ArrayList<>());
                mp.get(diagonalSum).add(mat[i][j]);
            }
        }
        
        int[] ans = new int[m * n];
        int index = 0;
        boolean flag = true;
        
        for (Map.Entry<Integer, ArrayList<Integer>> entry : mp.entrySet()) {
            ArrayList<Integer> diagonalElements = entry.getValue();
            if (flag) {
                Collections.reverse(diagonalElements);
            }
            for (int num : diagonalElements) {
                ans[index++] = num;
            }
            flag = !flag;
        }
        
        return ans;
    }
}