/*
 * @lc app=leetcode id=1675 lang=cpp
 *
 * [1675] Minimize Deviation in Array
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
  int minimumDeviation(vector<int>& nums) {
    set<int> st;
    for(auto i : nums) {
      st.insert((i & 1) ? (i << 1) : i);
    }
    
    int answer = *st.rbegin() - *st.begin();
    while(*st.rbegin() % 2 == 0) {
      st.insert(*st.rbegin() >> 1);
      st.erase(*st.rbegin());
      answer = min(answer, *st.rbegin() - *st.begin());
    }
    return answer;
  }
};

// Accepted
// 76/76 cases passed (503 ms)
// Your runtime beats 26.49 % of cpp submissions
// Your memory usage beats 9.93 % of cpp submissions (122.2 MB)
// @lc code=end
