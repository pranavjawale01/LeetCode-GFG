class Solution {
    public int minimumDeletions(String s) {
        int n = s.length();
        int counta = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == 'a') {
                counta++;
            }
        }
        int count = Integer.MAX_VALUE;
        int countb = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'a') {
                counta--;
            }
            count = Math.min(count, countb + counta);
            if (s.charAt(i) == 'b') {
                countb++;
            }
        }
        return count;
    }
}






// class Solution {
//     public int minimumDeletions(String s) {
//         int n = s.length();
//         int[] rightA = new int[n];
//         int countA = 0;
        
//         for (int i = n - 1; i >= 0; i--) {
//             rightA[i] = countA;
//             if (s.charAt(i) == 'a') {
//                 countA++;
//             }
//         }
        
//         int count = Integer.MAX_VALUE;
//         int countB = 0;
        
//         for (int i = 0; i < n; i++) {
//             count = Math.min(count, countB + rightA[i]);
//             if (s.charAt(i) == 'b') {
//                 countB++;
//             }
//         }
        
//         return count;
//     }
// }





// class Solution {
//     public int minimumDeletions(String s) {
//         int n = s.length();
//         int[] leftB = new int[n];
//         int[] rightA = new int[n];
        
//         int countB = 0;
//         for (int i = 0; i < n; i++) {
//             leftB[i] = countB;
//             if (s.charAt(i) == 'b') {
//                 countB++;
//             }
//         }
        
//         int countA = 0;
//         for (int i = n - 1; i >= 0; i--) {
//             rightA[i] = countA;
//             if (s.charAt(i) == 'a') {
//                 countA++;
//             }
//         }
        
//         int count = Integer.MAX_VALUE;
//         for (int i = 0; i < n; i++) {
//             count = Math.min(count, leftB[i] + rightA[i]);
//         }
        
//         return count;
//     }
// }






// class Solution {
//     public int minimumDeletions(String s) {
//         int n = s.length();
//         int count = 0;
//         Stack<Character> stack = new Stack<>();
        
//         for (int i = 0; i < n; i++) {
//             if (!stack.isEmpty() && s.charAt(i) == 'a' && stack.peek() == 'b') {
//                 stack.pop();
//                 count++;
//             } else {
//                 stack.push(s.charAt(i));
//             }
//         }
        
//         return count;
//     }
// }