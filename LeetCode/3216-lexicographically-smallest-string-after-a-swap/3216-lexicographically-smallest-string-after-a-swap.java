class Solution {
    public String getSmallestString(String s) {
        StringBuilder sb = new StringBuilder(s);
        int n = sb.length();
        for (int i = 0; i < n - 1; i++) {
            if ((sb.charAt(i) - '0') % 2 == (sb.charAt(i + 1) - '0') % 2) {
                if (sb.charAt(i) > sb.charAt(i + 1)) {
                    char temp = sb.charAt(i);
                    sb.setCharAt(i, sb.charAt(i + 1));
                    sb.setCharAt(i + 1, temp);
                    break;
                }
            }
        }
        return sb.toString();

    }
}