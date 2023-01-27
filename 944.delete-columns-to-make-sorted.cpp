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
      string cur(count, 0);
      for(int j = 0; j < count; ++j) {
        cur[j] = strs[j][i];
      }
      answer += !is_sorted(cur.begin(), cur.end());
    }
    return answer;
  }
};

// Accepted
// 85/85 cases passed (44 ms)
// Your runtime beats 87.58 % of cpp submissions
// Your memory usage beats 10.77 % of cpp submissions (14.9 MB)
// @lc code=end

