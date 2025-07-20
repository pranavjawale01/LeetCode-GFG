class Solution {
    private int compareFunction(int a, int b) {
        String c = String.valueOf(a);
        String d = String.valueOf(b);
        return (d+c).compareTo(c+d);
    }
    public String largestNumber(int[] nums) {
        Integer[] arr = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        Arrays.sort(arr, this::compareFunction);
        if (arr[0] == 0) {
            return "0";
        }
        StringBuilder ans = new StringBuilder();
        for (int x : arr) {
            ans.append(x);
        }
        return ans.toString();
    }
}
// class Solution {
//     public String largestNumber(int[] nums) {
//         Integer[] arr = Arrays.stream(nums).boxed().toArray(Integer[]::new);
//         Arrays.sort(arr, (a, b) -> {
//             String c = String.valueOf(a);
//             String d = String.valueOf(b);
//             return (d+c).compareTo(c+d);
//         });
//         if (arr[0] == 0) {
//             return "0";
//         }
//         StringBuilder ans = new StringBuilder();
//         for (int x : arr) {
//             ans.append(x);
//         }
//         return ans.toString();
//     }
// }