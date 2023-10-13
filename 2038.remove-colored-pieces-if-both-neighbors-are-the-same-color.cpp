/*
 * @lc app=leetcode id=2038 lang=cpp
 *
 * [2038] Remove Colored Pieces if Both Neighbors are the Same Color
 */

// @lc code=start
class Solution {
public:
  bool winnerOfGame(string colors) {
    int nums[2] = {};
    char color = colors.front();
    int count = 0;
    for(auto c : colors) {
      if(c == color) {
        count += 1;
      } else {
        nums[color - 'A'] += max(0, count - 2);
        color = c;
        count = 1;
      }
    }
    nums[color - 'A'] += max(0, count - 2);
    return nums[0] > nums[1];
  }
};

// Accepted
// 83/83 cases passed (34 ms)
// Your runtime beats 57.13 % of cpp submissions
// Your memory usage beats 23.75 % of cpp submissions (13.5 MB)
// @lc code=end

