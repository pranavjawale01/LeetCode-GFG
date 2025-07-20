class Solution {
    private String solve(String s) {
        StringBuilder temp = new StringBuilder();
        for (char c : s.toCharArray()) {
            temp.append((char) (c + 1));
        }
        return s + temp.toString();
    }
    
    public char kthCharacter(int k) {
        String s = "a";
        while (s.length() < k) {
            s = solve(s);
        }
        return s.charAt(k - 1);
    }
}