class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long ans = mass;
        sort(asteroids.begin(), asteroids.end());
        for (int x : asteroids) {
            if (x <= ans) {
                ans += x;
            } else {
                return false;
            }
        }
        return true;
    }
};