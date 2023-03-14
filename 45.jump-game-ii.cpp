/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
  int jump(vector<int>& nums) {
    int len = nums.size();
    queue<pair<int, int>> q;
    q.push({0, nums[0]});
    nums[0] = -1;
    int answer = 0;
    while(q.size()) {
      int sz = q.size();
      // cout << "round " << answer << ": " << endl;
      for(int i = 0; i < sz; ++i) {
        auto [index, offset] = q.front();
        // cout << index << ' ' << offset << endl;
        if(index == len - 1) return answer;
        q.pop();
        for(int j = max(0, index - offset); j < min(len, index + offset + 1); ++j) {
          if(nums[j] < 0) continue;
          q.push({j, nums[j]});
          nums[j] = - 1;
        }
      }
      // cout << endl;
      answer += 1;
    }
    return -1;
  }
};

// Accepted
// 109/109 cases passed (356 ms)
// Your runtime beats 32.61 % of cpp submissions
// Your memory usage beats 15.91 % of cpp submissions (17.7 MB)
// @lc code=end

