class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int m = box.length;
        int n = box[0].length;
        char[][] result = new char[n][m];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }
        
        for (char[] row : result) {
            reverseRow(row);
        }
        
        for (int j = 0; j < m; j++) {
            int spaceBottomRow = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (result[i][j] == '*') {
                    spaceBottomRow = i - 1;
                } else if (result[i][j] == '#') {
                    result[i][j] = '.';
                    result[spaceBottomRow][j] = '#';
                    spaceBottomRow--;
                }
            }
        }
        
        return result;
    }
    
    private void reverseRow(char[] row) {
        int left = 0, right = row.length - 1;
        while (left < right) {
            char temp = row[left];
            row[left] = row[right];
            row[right] = temp;
            left++;
            right--;
        }
    }
}











// class Solution {
//     public char[][] rotateTheBox(char[][] box) {
//         int m = box.length, n = box[0].length;
//         char[][] ans = new char[n][m];

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 ans[j][m - 1 - i] = box[i][j];
//             }
//         }

//         for (int j = 0; j < m; j++) {
//             for (int i = n - 1; i >= 0; i--) {
//                 if (ans[i][j] == '.') {
//                     int stoneRow = -1;
//                     for (int k = i - 1; k >= 0; k--) {
//                         if (ans[k][j] == '*') break;
//                         if (ans[k][j] == '#') {
//                             stoneRow = k;
//                             break;
//                         }
//                     }
//                     if (stoneRow != -1) {
//                         ans[i][j] = '#';
//                         ans[stoneRow][j] = '.';
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// }