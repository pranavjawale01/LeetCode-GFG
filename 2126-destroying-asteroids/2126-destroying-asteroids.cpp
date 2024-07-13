class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        for (int x : asteroids) {
            if (mass >= x) {
                mass += x;
            } else {
                return false;
            }
        }
        return true;
    }
};