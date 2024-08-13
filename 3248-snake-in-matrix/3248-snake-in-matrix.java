class Solution {
    public int finalPositionOfSnake(int n, List<String> commands) {
        int count = 0;
        for (String x : commands) {
            if (x.equals("UP")) {
                count -= n;
            } else if (x.equals("DOWN")) {
                count += n;
            } else if (x.equals("RIGHT")) {
                count++;
            } else if (x.equals("LEFT")) {
                count--;
            }
        }
        return count;
    }
}