class Solution {
    public int maximumSwap(int num) {
        String s = Integer.toString(num);
        int len = s.length();
        int[] maxRight = new int[len];
        maxRight[len - 1] = len - 1;
        
        for (int i = len - 2; i >= 0; i--) {
            int rightMaxIdx = maxRight[i + 1];
            char rightMaxElement = s.charAt(rightMaxIdx);
            maxRight[i] = (s.charAt(i) > rightMaxElement) ? i : rightMaxIdx;
        }
        
        for (int i = 0; i < len; i++) {
            int maxRightIdx = maxRight[i];
            char maxRightElement = s.charAt(maxRightIdx);
            if (s.charAt(i) < maxRightElement) {
                StringBuilder sb = new StringBuilder(s);
                sb.setCharAt(i, maxRightElement);
                sb.setCharAt(maxRightIdx, s.charAt(i));
                return Integer.parseInt(sb.toString());
            }
        }
        
        return num;
    }
}