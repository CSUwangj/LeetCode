/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
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
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for(auto s : strs) {
      string key = s;
      sort(key.begin(), key.end());
      groups[key].push_back(s);
    }
    vector<vector<string>> answer;
    for(auto [key, group] : groups) {
      answer.emplace_back(group);
    }
    return answer;
  }
};

// Accepted
// 114/114 cases passed (28 ms)
// Your runtime beats 89.97 % of cpp submissions
// Your memory usage beats 35.7 % of cpp submissions (20.8 MB)
// @lc code=end

