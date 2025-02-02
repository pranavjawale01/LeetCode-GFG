class Solution {
public:
    int maxDistance(string s, int k) {
        int north = 0, south = 0, east = 0, west = 0;
        int ans = 0;
        for (char c : s) {
            if (c == 'N') north++;
            if (c == 'S') south++;
            if (c == 'E') east++;
            if (c == 'W') west++;
            int maxVertical = max(north, south);
            int minVertical = min(north, south);
            int maxHorizontal = max(west, east);
            int minHorizontal = min(west, east);
            int kChanges = min(k, minVertical + minHorizontal);
            ans = max(ans, maxVertical + maxHorizontal - minVertical - minHorizontal + 2 * kChanges);
        }
        return ans;
    }
};