/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    set<int> st1(nums1.begin(), nums1.end());
    set<int> st2(nums2.begin(), nums2.end());

    vector<vector<int>> answer(2);
    for(auto n1 : st1) {
      if(!st2.count(n1)) {
        answer[0].push_back(n1);
      }
    }
    for(auto n2 : st2) {
      if(!st1.count(n2)) {
        answer[1].push_back(n2);
      }
    }

    return answer;
  }
};

// Accepted
// 202/202 cases passed (60 ms)
// Your runtime beats 63.81 % of cpp submissions
// Your memory usage beats 53.88 % of cpp submissions (32.7 MB)
// @lc code=end

