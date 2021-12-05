/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
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
  int largestRectangleArea(vector<int>& heights) {
    vector<int> st{-1};
    heights.push_back(0);
    int len = heights.size();
    int answer = 0;
    for(int i = 0; i < len; ++i) {
      while(st.back() != -1 && heights[i] < heights[st.back()]) {
        int index = st.back();
        st.pop_back();
        int h = heights[index];
        int w = i - st.back() - 1;
        answer = max(answer, h*w);
      }
      st.push_back(i);
    }
    return answer;
  }
};

// Accepted
// 96/96 cases passed (64 ms)
// Your runtime beats 99.7 % of cpp submissions
// Your memory usage beats 45.71 % of cpp submissions (64.8 MB)
// @lc code=end
