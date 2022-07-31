/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 */

// @lc code=start
class Solution {
public:
  int nextGreaterElement(int n) {
    string answer = to_string(n);
    int ans;
    if(next_permutation(answer.begin(), answer.end())) {
      if(stoll(answer) > INT_MAX) {
        ans = -1;
      } else {
        ans = stoi(answer);
      }
    } else {
      ans = -1;
    }
    return ans;
  }
};

// Accepted
// 39/39 cases passed (2 ms)
// Your runtime beats 43.51 % of cpp submissions
// Your memory usage beats 66.16 % of cpp submissions (6 MB)
// @lc code=end

