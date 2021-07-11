/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
int num[90000];
class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    if(k == 1) return matrix.front().front();
    int n = matrix.size();
    if(k == n * n) return matrix.back().back();
    memset(num, 0, sizeof(int) * n * n);
    int cnt = 0;
    for(auto &row : matrix) {
      for(auto i : row) {
        num[cnt++] = i;
      }
    }
    nth_element(num, num + k - 1, num + n * n);
    return num[k - 1];
  }
};

// Accepted
// 85/85 cases passed (24 ms)
// Your runtime beats 95.29 % of cpp submissions
// Your memory usage beats 57.08 % of cpp submissions (13.2 MB)
// @lc code=end

