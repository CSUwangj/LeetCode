/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 */

// @lc code=start
class Solution {
public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    int i1 = 0, i2 = 0, s1 = 0, s2 = 0;
    int len1 = word1.size(), len2 = word2.size();
    while(i1 < len1 && i2 <len2) {
      if(word1[i1][s1] != word2[i2][s2]) return false;
      s1 += 1;
      if(s1 == word1[i1].length()) s1 = 0, i1 += 1;
      s2 += 1;
      if(s2 == word2[i2].length()) s2 = 0, i2 += 1;
    }
    if(i1 != len1 || i2 != len2) return false;
    return true;
  }
};

// Accepted
// 109/109 cases passed (3 ms)
// Your runtime beats 93.69 % of cpp submissions
// Your memory usage beats 89.94 % of cpp submissions (11.4 MB)
// @lc code=end

