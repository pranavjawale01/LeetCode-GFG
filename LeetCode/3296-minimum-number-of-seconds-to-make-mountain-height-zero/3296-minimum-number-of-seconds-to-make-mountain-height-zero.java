class Solution {
    public long binarySearch(int workerTime, long availableTime, int mountainHeight) {
        long low = 0, high = mountainHeight, maxHeight = 0;
        while (low <= high) {
            long mid = low + (high - low) / 2;
            long requiredTime = workerTime * (mid * (mid + 1)) / 2;
            if (requiredTime <= availableTime) {
                maxHeight = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return maxHeight;
    }
    
    public boolean solve(int mountainHeight, int[] workerTimes, long time) {
        long total = 0;
        for (int x : workerTimes) {
            total += binarySearch(x, time, mountainHeight);
            if (total >= mountainHeight) {
                return true;
            }
        }
        return total >= mountainHeight;
    }
    
    public long minNumberOfSeconds(int mountainHeight, int[] workerTimes) {
        long low = 0, high = 1000000000000000000L;
        while (low < high) {
            long mid = low + (high - low) / 2;
            if (solve(mountainHeight, workerTimes, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}