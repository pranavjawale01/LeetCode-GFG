class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        left[0] = height[0];
        right[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            result += min(left[i], right[i]) - height[i];
        }
        
        return result;
    }
};


// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int left = 0, right = height.size() - 1, res = 0;
//         int maxLeft = 0, maxRight = 0;
//         while (left <= right) {
//             if (height[left] <= height[right]) {
//                 if (height[left] > maxLeft) {
//                     maxLeft = height[left];
//                 } else {
//                     res += maxLeft - height[left];
//                 }
//                 left++;
//             } else {
//                 if (height[right] > maxRight) {
//                     maxRight = height[right];
//                 } else {
//                     res += maxRight - height[right];
//                 }
//                 right--;
//             }
//         }
//         return res;
//     }
// };