class Solution {
    public String reverseWords(String s) {
        s = new StringBuilder(s).reverse().toString();
        int n = s.length(), i = 0;
        while (i < n && s.charAt(i) == ' ') i++;
        StringBuilder ans = new StringBuilder();
        StringBuilder temp = new StringBuilder();
        for (; i < n; i++) {
            if (s.charAt(i) == ' ') {
                if (temp.length() > 0) {
                    ans.append(temp.reverse()).append(" ");
                    temp.setLength(0);
                }
            } else {
                temp.append(s.charAt(i));
            }
        }
        if (temp.length() > 0) ans.append(temp.reverse());
        else if (ans.length() > 0) ans.setLength(ans.length() - 1);
        return ans.toString();
    }
}