/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
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
  double average(vector<int>& salary) {
    int sum = accumulate(salary.begin(), salary.end(), 0);
    int mmin = *min_element(salary.begin(), salary.end());
    int mmax = *max_element(salary.begin(), salary.end());

    return (sum - mmin - mmax) * 1.0 / (salary.size() - 2);
  }
};

// Accepted
// 43/43 cases passed (5 ms)
// Your runtime beats 23.02 % of cpp submissions
// Your memory usage beats 84.06 % of cpp submissions (7.1 MB)
// @lc code=end

