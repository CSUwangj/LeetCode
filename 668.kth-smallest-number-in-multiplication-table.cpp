/*
 * @lc app=leetcode id=668 lang=cpp
 *
 * [668] Kth Smallest Number in Multiplication Table
 */

// @lc code=start
class Solution {
  int count(int rows, int col, int num) {
    int row = 1;
    int cnt = 0;
    while(row <= rows && col) {
      if(row * col <= num) {
        cnt += col;
        row += 1;
      } else {
        col -= 1;
      }
    }
    return cnt;
  }
public:
  int findKthNumber(int m, int n, int k) {
    int low = 1;
    int high = m * n;
    if(k == 1) return low;
    if(k == n * m) return high;
    while(low < high) {
      int mid = (low + high) >> 1;
      if(count(m, n, mid) < k) {
        low = mid + 1;
      }else{
        high = mid;
      }
    }
    return low;
  }
};

// Accepted
// 70/70 cases passed (12 ms)
// Your runtime beats 95.06 % of cpp submissions
// Your memory usage beats 68.64 % of cpp submissions (5.9 MB)
// @lc code=end

