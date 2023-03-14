/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int time(const vector<int> &piles, int eat) {
    int result = 0;
    for(auto pile : piles) {
      if(pile % eat) {
        result += pile / eat + 1;
      } else {
        result += pile / eat;
      }
    }
    return result;
  }
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    while(low < high) {
      int mid = (low + high) >> 1;
      if(time(piles, mid) > h) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};

// Accepted
// 123/123 cases passed (37 ms)
// Your runtime beats 96.29 % of cpp submissions
// Your memory usage beats 45.12 % of cpp submissions (18.9 MB)
// @lc code=end
