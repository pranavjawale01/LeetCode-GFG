class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<>();

        for (int i = 0; i < numRows; i++) {
            List<Integer> row = new ArrayList<>();
            row.add(1);
            for (int j = 1; j < i; j++) {
                int prev1 = triangle.get(i - 1).get(j - 1);
                int prev2 = triangle.get(i - 1).get(j);
                row.add(prev1 + prev2);
            }
            
            if (i > 0) {
                row.add(1);
            }
            
            triangle.add(row);
        }

        return triangle;
    }
}