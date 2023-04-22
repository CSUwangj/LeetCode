/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
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
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maximum = *max_element(candies.begin(), candies.end());
    vector<bool> answer;
    answer.reserve(candies.size());

    for(auto candy : candies) {
      if(candy + extraCandies >= maximum) {
        answer.push_back(true);
      } else {
        answer.push_back(false);
      }
    }
    return answer;
  }
};

// Accepted
// 103/103 cases passed (8 ms)
// Your runtime beats 18.19 % of cpp submissions
// Your memory usage beats 86.24 % of cpp submissions (8.9 MB)
// @lc code=end

