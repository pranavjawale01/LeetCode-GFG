class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int lastDayCovered = 0;
        int dayWithoutMeeting = 0;

        for (const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];

            dayWithoutMeeting += max(0, start - lastDayCovered - 1);

            lastDayCovered = max(lastDayCovered, end);
        }

        dayWithoutMeeting += max(0, days - lastDayCovered);

        return dayWithoutMeeting;
    }
};