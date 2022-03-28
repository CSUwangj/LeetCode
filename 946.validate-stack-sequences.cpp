/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */

// @lc code=start
class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    vector<int> st;
    int pos = 0;
    int len = pushed.size();
    for(int i = 0; i < len; ++i) {
      while(pos < len && (st.empty() || st.back() != popped[i])) {
        st.push_back(pushed[pos]);
        pos += 1;
      }
      if(st.back() != popped[i]) return false;;
      st.pop_back();
    }
    return true;
  }
};

// Accepted
// 151/151 cases passed (4 ms)
// Your runtime beats 97.31 % of cpp submissions
// Your memory usage beats 59.16 % of cpp submissions (15.4 MB)
// @lc code=end
