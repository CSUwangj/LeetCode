/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
int ones[50000];
class Solution {
public:
  int longestOnes(vector<int>& nums, int k) {
    int s = accumulate(nums.begin(), nums.end(), 0);
    int len = nums.size();
    if(s + k >= len) return len;
    int answer = 0;
    int last = -1;
    int ed = 0;
    int start = 0;
    for(int i = 0; i < len; ++i) {
      if(!nums[i]) {
        if(!k) {
          last = i;
        } else {
          if(ed - start == k) last = ones[start++];
          ones[ed++] = i;
          start %= 50000;
          ed %= 50000;
        }
      }
      // cout << i << ' ' << last << ' ' << ed << ' ' << start << endl;
      answer = max(answer, i - last);
    }
    return answer;
  }
};
// @lc code=end

