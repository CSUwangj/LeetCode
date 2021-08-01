/*
 * @lc app=leetcode id=932 lang=cpp
 *
 * [932] Beautiful Array
 */

// @lc code=start
class Solution {
public:
  vector<int> beautifulArray(int n) {
    vector<int> answer{1};
    vector<int> tmp;
    while(answer.size() < n) {
      for(auto i : answer) {
        if(i * 2 - 1 <= n) tmp.push_back(i * 2 - 1);
      }
      for(auto i : answer) {
        if(i * 2 <= n) tmp.push_back(i * 2);
      }
      swap(tmp, answer);
      tmp.clear();
    }
    return answer;
  }
};

// Accepted
// 38/38 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 90.59 % of cpp submissions (6.9 MB)
// @lc code=end

