class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) return s;

        int len = s.length();
        char[] result = new char[len];
        int cycleLen = 2 * numRows - 2;
        int k = 0;

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j + i < len; j += cycleLen) {
                result[k++] = s.charAt(j + i);
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < len) {
                    result[k++] = s.charAt(j + cycleLen - i);
                }
            }
        }

        return new String(result);
    }
}