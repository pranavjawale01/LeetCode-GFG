class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        List<Integer> fayda = new ArrayList<>();
        long normalSum = 0;

        for (int num : nums) {
            fayda.add((num ^ k) - num);
            normalSum += (long) num;
        }

        Collections.sort(fayda, Collections.reverseOrder());

        for (int i = 0; i < fayda.size() - 1; i += 2) {
            long pairSum = fayda.get(i) + fayda.get(i + 1);

            if (pairSum > 0) {
                normalSum += pairSum;
            }
        }
        return normalSum;
    }
}


// class Solution {
//     public long maximumValueSum(int[] nums, int k, int[][] edges) {
//         long sum = 0;
//         int count = 0;
//         int minLoss = Integer.MAX_VALUE;
        
//         for (int num : nums) {
//             if ((num ^ k) > num) {
//                 count++;
//                 sum += (num ^ k);
//             } else {
//                 sum += num;
//             }
//             minLoss = Math.min(minLoss, Math.abs(num - (num ^ k)));
//         }
        
//         if (count % 2 == 0) {
//             return sum;
//         }
//         return sum - minLoss;
//     }
// }