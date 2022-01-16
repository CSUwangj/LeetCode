/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
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
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> answer;
    sort(nums.begin(), nums.end());
    do {
      answer.push_back(nums);
    } while(next_permutation(nums.begin(), nums.end()));
    return answer;
  }
};

// Accepted
// 26/26 cases passed (4 ms)
// Your runtime beats 70.64 % of cpp submissions
// Your memory usage beats 78.16 % of cpp submissions (7.6 MB)
// @lc code=end
