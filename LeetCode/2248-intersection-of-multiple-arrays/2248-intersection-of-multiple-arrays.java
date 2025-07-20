class Solution {
    public List<Integer> intersection(int[][] nums) {
        int n = nums.length;
        int[] arr = new int[1001];
        for (int[] num : nums) {
            for (int x : num) {
                arr[x]++;
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < 1001; i++) {
            if (arr[i] == n) {
                ans.add(i);
            }
        }
        return ans;
    }
}




// class Solution {
//     public List<Integer> intersection(int[][] nums) {
//         int n = nums.length;
//         Map<Integer, Integer> mp = new HashMap<>();
//         for (int[] num : nums) {
//             for (int x : num) {
//                 mp.put(x, mp.getOrDefault(x, 0) + 1);
//             }
//         }
//         List<Integer> ans = new ArrayList<>();
//         for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
//             if (entry.getValue() == n) {
//                 ans.add(entry.getKey());
//             }
//         }
//         Collections.sort(ans);
//         return ans;
//     }
// }