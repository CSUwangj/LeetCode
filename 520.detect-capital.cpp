/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution {
public:
  bool detectCapitalUse(string word) {
    int count = 0;
    for(auto c : word) {
      count += !!isupper(c);
    }
    // int count = count_if(word.begin(), word.end(), isupper);
    return count == word.length() || count == 0 || (count == 1 && isupper(word.front()));
  }
};

// Accepted
// 550/550 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 67.65 % of cpp submissions (6 MB)
// @lc code=end