class Solution {
    public boolean isPathCrossing(String path) {
        Set<String> visited = new HashSet<>();
        visited.add("0,0");

        int x = 0, y = 0;

        for (char direction : path.toCharArray()) {
            if (direction == 'N') {
                y++;
            } else if (direction == 'S') {
                y--;
            } else if (direction == 'E') {
                x++;
            } else if (direction == 'W') {
                x--;
            }

            if (!visited.add(x + "," + y)) {
                return true;
            }
        }
        return false;
    }
}