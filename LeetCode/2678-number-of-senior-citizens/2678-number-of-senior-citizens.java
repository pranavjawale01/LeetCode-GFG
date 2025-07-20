class Solution {
    public int countSeniors(String[] details) {
        int count = 0;
        for (String x : details) {
            int age = x.charAt(11) - '0';
            age = age * 10 + x.charAt(12) - '0';
            if (age > 60) {
                count++;
            }
        }
        return count;
    }
}