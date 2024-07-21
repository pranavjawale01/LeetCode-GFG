class Solution {
public:
    int minChanges(int n, int k) {
        if ((n | k) != n) {
            return -1;
        }
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if ((n & (1 << i)) && !(k & (1 << i))) {
                count++;
            }
        }
        return count;
    }
};