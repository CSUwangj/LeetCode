/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    for(auto letter : letters) {
      if(letter > target) return letter;
    }
    return letters[0];
  }
};

// Accepted
// 167/167 cases passed (15 ms)
// Your runtime beats 75.46 % of cpp submissions
// Your memory usage beats 96.78 % of cpp submissions (15.8 MB)
// @lc code=end

