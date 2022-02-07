/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
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
  int findMaxLength(vector<int>& nums) {
    int len = nums.size();
    int pos[2 * len + 1];
    memset(pos, -1, sizeof(pos));
    pos[len] = 0;
    
    int all = 0;
    int one = 0;
    int answer = 0;
    for(auto n : nums) {
      if(n) {
        one += 1;
      } else {
        one -= 1;
      }
      all += 1;
      if(pos[one + len] != -1) {
        answer = max(answer, all - pos[one + len]);
      } else {
        pos[one + len] = all;
      }
    }
    return answer;
  }
};

// Accepted
// 564/564 cases passed (100 ms)
// Your runtime beats 97.6 % of cpp submissions
// Your memory usage beats 99.64 % of cpp submissions (79.9 MB)
// @lc code=end
