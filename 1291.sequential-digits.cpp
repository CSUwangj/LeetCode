/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 */

// @lc code=start
const vector<int> nums{1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789};
class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    int diff = 0;
    vector<int> answer;
    for(auto num : nums) {
      diff = diff * 10 + 1;
      if(num > high) break;
      while(num % 10 && num <= high) {
        if(num >= low) answer.push_back(num);
        num += diff;
      }
    }
    return answer;
  }
};

// Accepted
// 23/23 cases passed (3 ms)
// Your runtime beats 18.21 % of cpp submissions
// Your memory usage beats 76.43 % of cpp submissions (6.2 MB)
// @lc code=end
