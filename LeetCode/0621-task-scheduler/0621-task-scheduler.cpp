class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int taskFreqMp[26] = {0};
        for (char c : tasks) {
            taskFreqMp[c - 'A']++;
        }
        
        sort(taskFreqMp, taskFreqMp + 26);
        
        int batchCnt = taskFreqMp[25];
        int vacantSlots = (--batchCnt) * n;
        for (int indx = 0; indx < 25; indx++) {
            vacantSlots -= min(taskFreqMp[indx], batchCnt);
        }
        
        return (vacantSlots > 0) ? tasks.size() + vacantSlots : tasks.size();
    }
};

// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         vector<int> mp(26, 0);
//         for (char ch : tasks) {
//             mp[ch - 'A']++;
//         }
//         int time = 0;
//         priority_queue<int> pq;
//         for (int i = 0; i < 26; i++) {
//             if (mp[i] > 0) {
//                 pq.push(mp[i]);
//             }
//         }
//         while(!pq.empty()) {
//             vector<int> temp;
//             for (int i = 1; i <= n + 1; i++) {
//                 if (!pq.empty()) {
//                     int freq = pq.top();
//                     pq.pop();
//                     freq--;
//                     temp.push_back(freq);
//                 }
//             }
//             for (int &f : temp) {
//                 if (f > 0) {
//                     pq.push(f);
//                 }
//             }
//             if (pq.empty()) {
//                 time += temp.size();
//             } else {
//                 time += n + 1;
//             }
//         }
//         return time;
//     }
// };