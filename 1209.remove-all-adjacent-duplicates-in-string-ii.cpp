/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start
class Solution {
public:
  string removeDuplicates(string s, int k) {
    vector<pair<char, int>> st;
    for(auto c : s) {
      if(st.empty() || st.back().first != c) {
        st.push_back(make_pair(c, 1));
      } else {
        st.back().second += 1;
        if(st.back().second == k) st.pop_back();
      }
    }
    string answer;
    for(auto [c, cnt] : st) {
      for(int i = 0; i < cnt; ++i) answer.push_back(c);
    }
    return answer;
  }
};

// Accepted
// 20/20 cases passed (25 ms)
// Your runtime beats 68.41 % of cpp submissions
// Your memory usage beats 54.02 % of cpp submissions (10.6 MB)
// @lc code=end
