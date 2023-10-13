/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
  string toRange(int begin, int end) {
    if(begin == end) return to_string(begin);
    return to_string(begin) + "->" + to_string(end);
  }
public:
  vector<string> summaryRanges(vector<int>& nums) {
    if(nums.empty()) return {};
    vector<string> answer;
    int begin = nums.front();
    int end = nums.front();
    for(auto n : nums) {
      if(n > min(end, INT_MAX - 1) + 1) {
        answer.push_back(toRange(begin, end));
        begin = end = n;
      } else {
        end = n;
      }
    }
    answer.push_back(toRange(begin, end));
    return answer;
  }
};

// Accepted
// 30/30 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 57.22 % of cpp submissions (6.8 MB)
// @lc code=end
