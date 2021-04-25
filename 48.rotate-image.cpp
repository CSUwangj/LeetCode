/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int low = n / 2;
        int high = n - low;
        for(int j = 0; j < high; ++j) {
            for(int i = 0; i+j < n-1-j; ++i) {
                swap(matrix[j][j+i], matrix[j+i][n-1-j]);
                swap(matrix[j][j+i], matrix[n-1-i-j][j]);
                swap(matrix[n-1-j][n-1-i-j], matrix[n-1-i-j][j]);
            }
        }
    }
};

// [0, 0], [0, n-1], [n-1, n-1], [n-1, 0] -> [n-1, 0], [0, 0], [0, n-1], [n-1, n-1]
// [0, 1], [1, n-1], [n-1, n-2], [n-2, 0] -> [n-2, 0], [0, 1], [1, n-1], [n-1, n-2]
// ...
// [0, i], [i, n-1], [n-1, n-1-i], [n-1-i, 0] -> ...
// ...
// [0, n-2], [n-2, n-1], [n-1, 1], [1, 0] -> ...

// [1, 1], [1, n-2], [n-2, n-2], [n-2, 1] -> ...
// [1, 2], [2, n-2], [n-2, n-3], [n-3, 1] -> ...
// ...
// [1, 1+i], [1+i, n-2], [n-2, n-2-i], [n-2-i, 1] -> ...

// [j, j+i], [j+i, n-1-j], [n-1-j, n-1-i-j], [n-1-i-j, j] -> ...
    
// @lc code=end

