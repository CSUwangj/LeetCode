/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */

// @lc code=start
class Solution {
public:
  bool isPossible(vector<int>& nums) {
    map<int, int> not_placed;
    map<int, int> end_with;
    for(auto n : nums) {
      not_placed[n] += 1;
    }

    for(auto n : nums) {
      if(!not_placed[n]) continue;
      not_placed[n] -= 1;
      if(end_with[n - 1]) {
        end_with[n - 1] -= 1;
        end_with[n] += 1;
      } else if(not_placed[n + 1] && not_placed[n + 2]) {
        not_placed[n + 1] -= 1;
        not_placed[n + 2] -= 1;
        end_with[n + 2] += 1;
      } else {
        return false;
      }
    }

    return true;
  }
};

// Accepted
// 186/186 cases passed (180 ms)
// Your runtime beats 43.45 % of cpp submissions
// Your memory usage beats 17.83 % of cpp submissions (59.2 MB)
// @lc code=end

