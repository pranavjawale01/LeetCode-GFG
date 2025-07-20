class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int x : target) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        for (int x : arr) {
            if (!mp.containsKey(x)) {
                return false;
            }
            mp.put(x, mp.getOrDefault(x, 0) - 1);
            if (mp.get(x) == 0) {
                mp.remove(x);
            }
        }
        return mp.size() == 0;
    }
}




// class Solution {
//     public boolean canBeEqual(int[] target, int[] arr) {
//         Arrays.sort(target);
//         Arrays.sort(arr);
//         return Arrays.equals(target, arr);
//     }
// }