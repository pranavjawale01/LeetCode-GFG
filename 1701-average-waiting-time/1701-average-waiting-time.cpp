class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waitTime = 0;
        int currTime = 0;
        for (auto &x : customers) {
            int arrivalTime = x[0];
            int cookTime = x[1];
            if (currTime < arrivalTime) {
                currTime = arrivalTime;
            }
            int wait = currTime + cookTime - arrivalTime;
            waitTime += wait;
            currTime += cookTime;
        }
        int n = customers.size();
        return waitTime / n;
    }
};