/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 */

// @lc code=start
class Solution {
public:
  int binaryGap(int n) {
    int previous = -1;
    int answer = 0;
    for(int i = 0; i < 31; ++i) {
      if(n & (1 << i)) {
        if(previous != -1) {
          answer = max(answer, i - previous);
        }
        previous = i;
      }
    }

    return answer;
  }
};

// Accepted
// 261/261 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 38.57 % of cpp submissions (6 MB)
// @lc code=end

