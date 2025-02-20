class Solution {
    public String findDifferentBinaryString(String[] nums) {
        Set<Integer> st = new HashSet<>();
        for (String x : nums) {
            st.add(Integer.parseInt(x, 2));
        }
        int n = nums.length;
        String ans = "";
        for (int num = 0; num <= n; num++) {
            if (!st.contains(num)) {
                ans = String.format("%16s", Integer.toBinaryString(num)).replace(' ', '0');
                break;
            }
        }
        return ans.substring(16-n);
    }
}








// class Solution {
//     public String findDifferentBinaryString(String[] nums) {
//         int n = nums.length;
//         StringBuilder ans = new StringBuilder();
        
//         for (int i = 0; i < n; i++) {
//             char ch = nums[i].charAt(i);
//             ans.append(ch == '0' ? '1' : '0');
//         }
        
//         return ans.toString();
//     }
// }







// // class Solution {
// //     Set<String> st = new HashSet<>();
// //     String ans = "";

// //     void solve(StringBuilder curr, int n) {
// //         if (curr.length() == n) {
// //             if (!st.contains(curr.toString())) {
// //                 ans = curr.toString();
// //             }
// //             return;
// //         }
// //         if (!ans.isEmpty()) return;

// //         curr.append('0');
// //         solve(curr, n);
// //         curr.deleteCharAt(curr.length() - 1);

// //         curr.append('1');
// //         solve(curr, n);
// //         curr.deleteCharAt(curr.length() - 1);
// //     }

// //     public String findDifferentBinaryString(String[] nums) {
// //         int n = nums[0].length();
// //         for (String num : nums) st.add(num);
// //         solve(new StringBuilder(), n);
// //         return ans;
// //     }
// // }