class Solution {
public:
    int candy(vector<int>& ratings) {
        int total_candy = 1;
        int up = 0, down = 0, peak = 0;
        int n = ratings.size();
        for (int i = 1; i < n; i++) {
            if (ratings[i-1] < ratings[i]) {
                peak = ++up;
                down = 0;
                total_candy += 1 + up;
            } else if (ratings[i-1] == ratings[i]) {
                peak = up = down = 0;
                total_candy += 1;
            } else {
                up = 0;
                down++;
                total_candy += 1 + down + (peak >= down ? -1 : 0);
            }
        }
        return total_candy;
    }
};