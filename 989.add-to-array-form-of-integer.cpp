/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
class Solution {
public:
  vector<int> addToArrayForm(vector<int>& A, int K) {
    reverse(A.begin(), A.end());
    int carry = 0;
    int pos = 0;
    int len = A.size();
    while(carry || K) {
      int result = carry + K % 10;
      if(pos < len) result += A[pos];
      carry = result / 10;
      if(pos < len) A[pos] = result % 10;
      else A.push_back(result % 10);
      K /= 10;
      pos += 1;
    }
    reverse(A.begin(), A.end());
    return move(A);
  }
};

// Accepted
// 152/152 cases passed (19 ms)
// Your runtime beats 98.87 % of cpp submissions
// Your memory usage beats 99.93 % of cpp submissions (26.4 MB)
// @lc code=end

