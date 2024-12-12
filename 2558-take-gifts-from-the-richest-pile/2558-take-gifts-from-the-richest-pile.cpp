class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        long long ans = accumulate(gifts.begin(), gifts.end(), 0ll);
        while (k--) {
            int maxEl = pq.top();
            pq.pop();
            ans -= (maxEl - sqrt(maxEl));
            pq.push(sqrt(maxEl));
        }
        return ans;
    }
};