/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
  int n;
  int count(vector<vector<int>>& matrix, int num) {
    int row = 0;
    int col = n - 1;
    int cnt = 0;
    while(row < n && col >= 0) {
      if(matrix[row][col] <= num) {
        cnt += col + 1;
        row += 1;
      } else {
        col -= 1;
      }
    }
    return cnt;
  }
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    n = matrix.size();
    int low = matrix.front().front();
    int high = matrix.back().back();
    if(k == 1) return low;
    if(k == n * n) return high;
    while(low < high) {
      int mid = (low + high) >> 1;
      if(count(matrix, mid) < k) {
        low = mid + 1;
      }else{
        high = mid;
      }
    }
    return low;
  }
};

// Accepted
// 85/85 cases passed (20 ms)
// Your runtime beats 99.01 % of cpp submissions
// Your memory usage beats 90.44 % of cpp submissions (13.1 MB)
// @lc code=end

