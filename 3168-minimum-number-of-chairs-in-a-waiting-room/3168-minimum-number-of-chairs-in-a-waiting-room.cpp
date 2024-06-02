class Solution {
public:
    int minimumChairs(string s) {
        int chair = 0;
        int available = 0;
        for (char c : s) {
            if (c == 'E') {
                available--;
                chair = min(chair, available);
            } else {
                available++;
                chair = min(chair, available);
            }
        }
        return chair * (-1);
    }
};