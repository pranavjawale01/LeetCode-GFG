class Solution {
    private int solve(StringBuilder s, String targetStr, int point) {
        int totalPoints = 0;
        int n = s.length();
        int writeIdx = 0;
        for (int readIdx = 0; readIdx < n; readIdx++) {
            s.setCharAt(writeIdx++, s.charAt(readIdx));
            if (writeIdx > 1 && s.charAt(writeIdx - 1) == targetStr.charAt(1) && s.charAt(writeIdx - 2) == targetStr.charAt(0)) {
                writeIdx -= 2;
                totalPoints += point;
            }
        }
        s.setLength(writeIdx);
        return totalPoints;
    }

    public int maximumGain(String s, int x, int y) {
        String s1 = "ab", s2 = "ba";
        if (y > x) {
            String tempStr = s1;
            s1 = s2;
            s2 = tempStr;

            int temp = x;
            x = y;
            y = temp;
        }

        StringBuilder sb = new StringBuilder(s);
        int points1 = solve(sb, s1, x);
        int points2 = solve(sb, s2, y);

        return points1 + points2;
    }
}





// class Solution {
//     private int solve(StringBuilder s, String targetStr, int point) {
//         int totalPoints = 0;
//         Stack<Character> st = new Stack<>();
//         for (int i = 0; i < s.length(); i++) {
//             if (st.isEmpty()) {
//                 st.push(s.charAt(i));
//             } else {
//                 if (s.charAt(i) == targetStr.charAt(1) && st.peek() == targetStr.charAt(0)) {
//                     st.pop();
//                     totalPoints += point;
//                 } else {
//                     st.push(s.charAt(i));
//                 }
//             }
//         }

//         s.setLength(0);
//         while (!st.isEmpty()) {
//             s.append(st.pop());
//         }
//         s.reverse();

//         return totalPoints;
//     }

//     public int maximumGain(String s, int x, int y) {
//         String s1 = "ab", s2 = "ba";
//         if (y > x) {
//             String tempStr = s1;
//             s1 = s2;
//             s2 = tempStr;

//             int temp = x;
//             x = y;
//             y = temp;
//         }

//         StringBuilder sb = new StringBuilder(s);
//         int points1 = solve(sb, s1, x);
//         int points2 = solve(sb, s2, y);

//         return points1 + points2;
//     }
// }