/*
 * @lc app=leetcode id=2009 lang=cpp
 *
 * [2009] Minimum Number of Operations to Make Array Continuous
 */

// @lc code=start
class Solution {
public:
  int minOperations(vector<int>& nums) {
    int sz = nums.size();
    int answer = sz;
    unordered_set<int> st;

    for(auto n : nums) {
      st.insert(n);
    }

    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());

    int pos = 0;
    for(int i = 0; i < nums.size(); ++i) {
      while(pos < nums.size() && nums[pos] < nums[i] + sz) {
        pos += 1;
      }
      answer = min(answer, sz - pos + i);
    }

    return answer;
  }
};

// Accepted
// 62/62 cases passed (250 ms)
// Your runtime beats 45.61 % of cpp submissions
// Your memory usage beats 41.84 % of cpp submissions (101.4 MB)
// @lc code=end

