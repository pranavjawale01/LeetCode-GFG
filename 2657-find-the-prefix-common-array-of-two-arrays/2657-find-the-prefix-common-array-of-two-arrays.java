class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        Map<Integer, Integer> map = new HashMap<>();
        int n = A.length;
        int[] result = new int[n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            map.put(A[i], map.getOrDefault(A[i], 0) + 1);
            map.put(B[i], map.getOrDefault(B[i], 0) + 1);
            if (A[i] == B[i]) {
                count++;
            } else {
                if (map.get(A[i]) == 2) count++;
                if (map.get(B[i]) == 2) count++;
            }
            result[i] = count;
        }
        return result;
    }
}