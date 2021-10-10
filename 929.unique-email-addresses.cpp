/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
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
  int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> st;
    for(auto &email : emails) {
      string result;
      bool at = false;
      bool plus = false;
      for(auto c : email) {
        at |= c == '@';
        if(at) {
          result.push_back(c);
        } else {
          plus |= c == '+';
          if(plus || c == '.') continue;
          result.push_back(c);
        }
      }
      st.insert(result);
    }
    return st.size();
  }
};

// Accepted
// 183/183 cases passed (16 ms)
// Your runtime beats 98.73 % of cpp submissions
// Your memory usage beats 74.59 % of cpp submissions (13.7 MB)
// @lc code=end

