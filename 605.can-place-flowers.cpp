/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
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
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    int flowers = 0;
    for(auto flowered : flowerbed) {
      if(flowered) {
        flowers += count / 2;
        count = -1;
      } else {
        count += 1;
      }
    }
    flowers += (count + 1) / 2;
    return flowers >= n;
  }
};

// Accepted
// 124/124 cases passed (10 ms)
// Your runtime beats 97.73 % of cpp submissions
// Your memory usage beats 34.3 % of cpp submissions (20.3 MB)
// @lc code=end
