class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunk = 0, prefixSum = 0, sortedPrefixSum = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];
            sortedPrefixSum += i;
            if (sortedPrefixSum == prefixSum) {
                chunk++;
            }
        }
        return chunk;
    }
};