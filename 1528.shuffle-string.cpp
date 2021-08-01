/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1528] Shuffle String
 */

// @lc code=start
class Solution {
public:
  string restoreString(string s, vector<int>& indices) {
    int len = s.length();
    string answer(len, 'a');
    for(int i = 0; i < len; ++i) {
      answer[indices[i]] = s[i];
    }
    return answer;
  }
};

// Accepted
// 399/399 cases passed (8 ms)
// Your runtime beats 73.74 % of cpp submissions
// Your memory usage beats 74.87 % of cpp submissions (15.2 MB)
// @lc code=end

