/*
 * @lc app=leetcode id=985 lang=cpp
 *
 * [985] Sum of Even Numbers After Queries
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
  vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> answer;
    answer.reserve(queries.size());

    int current = accumulate(nums.begin(), nums.end(), 0, [](int s, int a) {
      return s + !(a & 1) * a;
    });
    for(const auto &query : queries) {
      if(!(nums[query[1]] & 1)) {
        current -= nums[query[1]];
      }
      nums[query[1]] += query[0];
      if(!(nums[query[1]] & 1)) {
        current += nums[query[1]];
      }
      answer.push_back(current);
    }
    return answer;
  }
};

// Accepted
// 58/58 cases passed (191 ms)
// Your runtime beats 49.8 % of cpp submissions
// Your memory usage beats 85.52 % of cpp submissions (45.4 MB)
// @lc code=end

