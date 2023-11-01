class Solution {
    public String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        String temp = countAndSay(n - 1);
        StringBuilder result = new StringBuilder();
        int count = 1;        
        for (int i = 0; i < temp.length(); i++) {
            if (i + 1 < temp.length() && temp.charAt(i) == temp.charAt(i + 1)) {
                count++;
            } else {
                result.append(count).append(temp.charAt(i));
                count = 1;
            }
        }
        return result.toString();
    }
}