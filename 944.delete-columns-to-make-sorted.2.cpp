/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
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
  int minDeletionSize(vector<string>& strs) {
    int len = strs.front().length();
    int count = strs.size();
    int answer = 0;
    for(int i = 0; i < len; ++i) {
      for(int j = 1; j < count; ++j) {
        if(strs[j][i] < strs[j - 1][i]) {
          answer += 1;
          break;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 85/85 cases passed (30 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 30.23 % of cpp submissions (12.3 MB)
// @lc code=end

