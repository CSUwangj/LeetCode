/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
  int firstUniqChar(string s) {
    vector<int> pos(26, INT_MAX - 1);
    for(int i = 0; i < s.length(); ++i) {
      if(pos[s[i] - 'a'] == INT_MAX - 1) {
        pos[s[i] - 'a'] = i;
      } else {
        pos[s[i] - 'a'] = INT_MAX;
      }
    }
    int result = *min_element(pos.begin(), pos.end());
    return result > s.length() ? -1 : result;
  }
};

// Accepted
// 105/105 cases passed (32 ms)
// Your runtime beats 82.36 % of cpp submissions
// Your memory usage beats 91.52 % of cpp submissions (10.5 MB)
// @lc code=end

