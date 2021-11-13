/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreater;
    vector<int> monoStack;
    for(auto it = nums2.rbegin(); it != nums2.rend(); ++it) {
      while(monoStack.size() && monoStack.back() <= *it) monoStack.pop_back();
      nextGreater[*it] = monoStack.size() ? monoStack.back() : -1;
      monoStack.push_back(*it);
    }
    vector<int> answer(nums1.size());
    for(int i = 0; i < nums1.size(); ++i) {
      answer[i] = nextGreater[nums1[i]];
    }
    return answer;
  }
};

// Accepted
// 15/15 cases passed (10 ms)
// Your runtime beats 33.18 % of cpp submissions
// Your memory usage beats 58.15 % of cpp submissions (8.8 MB)
// @lc code=end

