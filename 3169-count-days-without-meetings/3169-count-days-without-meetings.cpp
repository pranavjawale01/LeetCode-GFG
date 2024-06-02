class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<vector<int>> merged;

        for (auto& meeting : meetings) {
            if (merged.empty() || merged.back()[1] < meeting[0]) {
                merged.push_back(meeting);
            } else {
                merged.back()[1] = max(merged.back()[1], meeting[1]);
            }
        }

        int day = 0;

        if (merged[0][0] > 1) {
            day += merged[0][0] - 1;
        }

        for (int i = 1; i < merged.size(); i++) {
            day += merged[i][0] - merged[i-1][1] - 1;
        }

        if (merged.back()[1] < days) {
            day += days - merged.back()[1];
        }

        return day;
    }
};





// class Solution {
// public:
//     int countDays(int days, vector<vector<int>>& meetings) {
//         sort(meetings.begin(), meetings.end());

//         int lastDayCovered = 0;
//         int dayWithoutMeeting = 0;

//         for (const auto& meeting : meetings) {
//             int start = meeting[0];
//             int end = meeting[1];

//             dayWithoutMeeting += max(0, start - lastDayCovered - 1);

//             lastDayCovered = max(lastDayCovered, end);
//         }

//         dayWithoutMeeting += max(0, days - lastDayCovered);

//         return dayWithoutMeeting;
//     }
// };