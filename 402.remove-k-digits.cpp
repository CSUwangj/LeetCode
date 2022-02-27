/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
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
  string removeKdigits(string num, int k) {
    string monoStack;
    int pos = 0;
    int len = num.length();
    while(pos < len) {
      while(k && monoStack.size() && monoStack.back() > num[pos]) {
        monoStack.pop_back();
        k -= 1;
      }
      if(num[pos] != '0' || monoStack.size()) monoStack.push_back(num[pos]);
      pos += 1;
    }
    while(k && monoStack.size()) {
      monoStack.pop_back();
      k -= 1;
    }
    if(monoStack.size()) return monoStack;
    return "0";
  }
};

// Accepted
// 40/40 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 88 % of cpp submissions (6.9 MB)
// @lc code=end
