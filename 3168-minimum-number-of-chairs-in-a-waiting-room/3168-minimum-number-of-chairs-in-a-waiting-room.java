class Solution {
    public int minimumChairs(String s) {
        int chair = 0, available = 0;
        for (char c : s.toCharArray()) {
            if (c == 'E') {
                available--;
                chair = Math.min(chair, available);
            } else {
                available++;
                chair = Math.min(chair, available);
            }
        }
        return chair * (-1);
    }
}