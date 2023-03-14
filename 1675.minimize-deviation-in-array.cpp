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
// 75/75 cases passed (319 ms)
// Your runtime beats 93.22 % of cpp submissions
// Your memory usage beats 37.29 % of cpp submissions (89.1 MB)
// @lc code=end
