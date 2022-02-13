/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
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
  vector<vector<int>> subsets(vector<int>& nums) {
    int len = nums.size();
    int sz = (1 << len);
    vector<vector<int>> answer;
    for(int i = 0; i < sz; ++i) {
      vector<int> st;
      for(int b = 0; b < len; ++b) {
        if(i & (1 << b)) st.push_back(nums[b]);
      }
      answer.emplace_back(move(st));
    }
    return answer;
  }
};

// Accepted
// 10/10 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 85.44 % of cpp submissions (7.1 MB)
// @lc code=end
