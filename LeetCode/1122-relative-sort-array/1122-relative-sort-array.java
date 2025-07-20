class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < arr2.length; i++) {
            mp.put(arr2[i], i);
        }
        int largeval = 1000000000;
        for (int i = 0; i < arr1.length; i++) {
            if (!mp.containsKey(arr1[i])) {
                mp.put(arr1[i], largeval);
            }
        }
        Comparator<Integer> cmp = (num1, num2) -> {
            int i1 = mp.get(num1);
            int i2 = mp.get(num2);
            if (i1 == i2) {
                return Integer.compare(num1, num2);
            }
            return Integer.compare(i1, i2);
        };
        List<Integer> arr = new ArrayList<>();
        for (int num : arr1) {
            arr.add(num);
        }
        Collections.sort(arr, cmp);
        for (int i = 0; i < arr1.length; i++) {
            arr1[i] = arr.get(i);
        }
        return arr1;
    }
}



// class Solution {
//     public int[] relativeSortArray(int[] arr1, int[] arr2) {
//         TreeMap<Integer, Integer> mp = new TreeMap<>();
//         for (int x : arr1) {
//             mp.put(x, mp.getOrDefault(x, 0) + 1);
//         }
        
//         List<Integer> ans = new ArrayList<>();
//         for (int x : arr2) {
//             while (mp.get(x) > 0) {
//                 ans.add(x);
//                 mp.put(x, mp.get(x) - 1);
//             }
//             mp.remove(x);
//         }
        
//         for (Map.Entry<Integer, Integer> x : mp.entrySet()) {
//             int key = x.getKey();
//             int value = x.getValue();
//             while (value > 0) {
//                 ans.add(key);
//                 value--;
//             }
//         }
        
//         int[] result = new int[ans.size()];
//         for (int i = 0; i < ans.size(); i++) {
//             result[i] = ans.get(i);
//         }
        
//         return result;
//     }
// }