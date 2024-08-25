class Solution {
    private long solve(long firstHalf, boolean isEven) {
        long resultNum = firstHalf;
        if (!isEven) {
            firstHalf /= 10;
        }
        while (firstHalf > 0) {
            int digit = (int)(firstHalf % 10);
            resultNum = resultNum * 10 + digit;
            firstHalf /= 10;
        }
        return resultNum;
    }

    public String nearestPalindromic(String n) {
        int l = n.length();
        int mid = l / 2;
        long firstHalfLen = (l % 2 == 0) ? mid : (mid + 1);
        long firstHalf = Long.parseLong(n.substring(0, (int)firstHalfLen));
        List<Long> possibleResults = new ArrayList<>();
        possibleResults.add(solve(firstHalf, l % 2 == 0));
        possibleResults.add(solve(firstHalf + 1, l % 2 == 0));
        possibleResults.add(solve(firstHalf - 1, l % 2 == 0));
        possibleResults.add((long)Math.pow(10, l - 1) - 1);
        possibleResults.add((long)Math.pow(10, l) + 1);

        long diff = Long.MAX_VALUE;
        long result = -1;
        long originalNum = Long.parseLong(n);

        for (long num : possibleResults) {
            if (num == originalNum) {
                continue;
            }
            if (Math.abs(num - originalNum) < diff) {
                diff = Math.abs(num - originalNum);
                result = num;
            } else if (Math.abs(num - originalNum) == diff) {
                result = Math.min(result, num);
            }
        }
        return String.valueOf(result);
    }
}





// class Solution {
//     public String nearestPalindromic(String n) {
//         int len = n.length();
//         long prefix = Long.parseLong(n.substring(0, (len + 1) / 2));
//         Set<Long> candidates = new TreeSet<>();
        
//         for (int i = -1; i <= 1; ++i) {
//             String p = Long.toString(prefix + i);
//             String pal = p + new StringBuilder(p).reverse().substring(len % 2);
//             candidates.add(Long.parseLong(pal));
//         }
        
//         candidates.add((long) Math.pow(10, len - 1) - 1);
//         candidates.add((long) Math.pow(10, len) + 1);
        
//         long num = Long.parseLong(n);
//         long minDiff = Long.MAX_VALUE;
//         long result = 0;
        
//         for (long candidate : candidates) {
//             if (candidate != num) {
//                 long diff = Math.abs(candidate - num);
//                 if (diff < minDiff || (diff == minDiff && candidate < result)) {
//                     minDiff = diff;
//                     result = candidate;
//                 }
//             }
//         }
        
//         return Long.toString(result);
//     }
// }