/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int begin = 0;
    int end = numbers.size() - 1;
    while(begin < end && numbers[begin] + numbers[end] != target) {
      if(numbers[begin] + numbers[end] < target) {
        begin += 1;
      } else {
        end -= 1;
      }
    }
    return {begin + 1, end + 1};
  }
};
// Accepted
// 19/19 cases passed (4 ms)
// Your runtime beats 88.71 % of cpp submissions
// Your memory usage beats 75.51 % of cpp submissions (9.6 MB)
// @lc code=end

