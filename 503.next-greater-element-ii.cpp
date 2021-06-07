/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int len = nums.size();
    vector<int> answer(len);
    vector<int> monoStack;
    for(int i = len - 1; i >= 0; --i) {
      int num = nums[i];
      while(monoStack.size() && monoStack.back() <= num) monoStack.pop_back();
      monoStack.push_back(num);
    }
    for(int i = len - 1; i >= 0; --i) {
      int num = nums[i];
      while(monoStack.size() && monoStack.back() <= num) monoStack.pop_back();
      answer[i] = monoStack.size() ? monoStack.back() : -1;
      monoStack.push_back(num);
    }
    return answer;
  }
};
// @lc code=end

