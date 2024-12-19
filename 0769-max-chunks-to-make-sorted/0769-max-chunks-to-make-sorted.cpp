class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunk = 0;
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int k = i;
            while (i < n - 1 && arr[i] > arr[i+1]) {
                i++;
            }
            if (i - k >= 1) chunk++;
            while (i < n - 1 && arr[i] < arr[i+1]) {
                chunk++;
                i++;
            }
        }
        return chunk == 0 ? 1 : chunk;
    }
};