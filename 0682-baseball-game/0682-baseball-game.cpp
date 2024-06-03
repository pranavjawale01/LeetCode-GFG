class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        for (const auto& op : operations) {
            if (op == "C") {
                score.pop_back();
            } else if (op == "D") {
                score.push_back(score.back() * 2);
            } else if (op == "+") {
                int n = score.size();
                score.push_back(score[n-1] + score[n-2]);
            } else {
                score.push_back(stoi(op));
            }
        }
        int sum = 0;
        for (const auto& s : score) {
            sum += s;
        }
        return sum;
    }
};