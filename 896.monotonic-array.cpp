/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 */

// @lc code=start
class Solution {
public:
  bool isMonotonic(vector<int>& A) {
    int len = A.size();
    if(len < 2) return true;
    int pos = 1;
    while(pos < len && A[pos] == A[pos-1]) pos += 1;
    if(pos == len) return true;
    if(A[pos] > A[pos-1]) {
      while(pos < len && A[pos] >= A[pos-1]) pos += 1;
      return pos==len;
    }
    while(pos < len && A[pos] <= A[pos-1]) pos += 1;
    return pos==len;
  }
};

// Accepted
// 371/371 cases passed (120 ms)
// Your runtime beats 67.15 % of cpp submissions
// Your memory usage beats 29.47 % of cpp submissions (96.7 MB)
// @lc code=end

