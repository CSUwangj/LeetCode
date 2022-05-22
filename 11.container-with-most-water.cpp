/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
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
  int maxArea(vector<int>& height) {
    int len = height.size();
    int left = 0, right = len - 1;
    int answer = (right - left) * min(height[left], height[right]);
    while(left < right) {
      if(height[left] < height[right]) {
        int tmp = height[left];
        while(left < right && height[left] <= tmp) ++left;
        answer = max(answer, (right - left) * min(height[left], height[right]));
      } else {
        int tmp = height[right];
        while(left < right && height[right] <= tmp) --right;
        answer = max(answer, (right - left) * min(height[left], height[right]));
      }
    }
    return answer;
  }
};

// Accepted
// 60/60 cases passed (150 ms)
// Your runtime beats 25.72 % of cpp submissions
// Your memory usage beats 38.72 % of cpp submissions (59.4 MB)
// @lc code=end
