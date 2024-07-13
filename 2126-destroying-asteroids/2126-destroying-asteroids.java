class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);
        long ans = mass;
        for (int x : asteroids) {
            if (x <= ans) {
                ans += x;
            } else {
                return false;
            }
        }
        return true;
    }
}