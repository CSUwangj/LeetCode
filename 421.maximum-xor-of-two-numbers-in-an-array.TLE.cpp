/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int conquer(set<int> &one, set<int> &zero, int pos) {
    if(pos <= 0 || one.size() <= 1 || zero.size() <= 1) {
      int answer = 0;
      for(auto o : one) {
        for(auto z : zero) {
          answer = max(answer, o ^ z);
        }
      }
      return answer;
    }
    set<int> oneOne, oneZero, zeroOne, zeroZero;
    for(auto o : one) {
      if(o & (1 << pos)) {
        oneOne.insert(o);
      } else {
        oneZero.insert(o);
      }
    }
    for(auto z : zero) {
      if(z & (1 << pos)) {
        zeroOne.insert(z);
      } else {
        zeroZero.insert(z);
      }
    }
    int result1 = conquer(oneOne, zeroZero, pos - 1);
    int result2 = conquer(zeroOne, oneZero, pos - 1);
    if(!result1 && !result2) {
      return conquer(one, zero, pos - 1);
    }
    return max(result1, result2);
  }
public:
  int findMaximumXOR(vector<int>& nums) {
    for(int i = 30; i >= 0; --i) {
      set<int> one, zero;
      for(auto num : nums) {
        if(num & (1 << i)) one.insert(num);
        else zero.insert(num);
      }
      if(one.size() && zero.size()) return conquer(one, zero, i - 1);
    }
    return 0;
  }
};

// Time Limit Exceeded
// 41/41 cases passed (N/A)
// @lc code=end
