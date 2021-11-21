/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
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
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> monoStack;
    int len = temperatures.size();
    vector<int> answer(len);
    for(int i = len - 1; i >= 0; --i) {
      while(monoStack.size() && temperatures[monoStack.back()] <= temperatures[i]) {
        monoStack.pop_back();
      }
      if(monoStack.size()) answer[i] = monoStack.back() - i;
      monoStack.push_back(i);
    }
    return answer;
  }
};

// Runtime: 96 ms, faster than 99.78% of C++ online submissions for Daily Temperatures.
// Memory Usage: 85 MB, less than 95.98% of C++ online submissions for Daily Temperatures.
// @lc code=end