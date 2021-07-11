/*
 * @lc app=leetcode id=1386 lang=cpp
 *
 * [1386] Cinema Seat Allocation
 */

// @lc code=start
auto speedup = []() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int MASK_MID   = 0B00011110000;
const int MASK_LEFT  = 0B01111000000;
const int MASK_RIGHT = 0B00000111100;
const int MASK_BOTH  = 0B01111111100;
const int INIT_MASK  = 0B11111111110;
constexpr inline int count(int mask) {
  if((mask & MASK_BOTH) == MASK_BOTH)   return 2;
  if((mask & MASK_LEFT) == MASK_LEFT)   return 1;
  if((mask & MASK_RIGHT) == MASK_RIGHT) return 1;
  if((mask & MASK_MID) == MASK_MID)     return 1;
  return 0;
}
class Solution {
public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    sort(reservedSeats.begin(), reservedSeats.end());
    int differentRow = 0;
    int row = -1;
    int mask = 0;
    int answer = 0;
    for(auto &seat : reservedSeats) {
      if(seat[0] != row) {
        answer += count(mask);
        mask = INIT_MASK;
        row = seat[0];
        differentRow += 1;
      }
      mask ^= (1 << seat[1]);
    }
    answer += count(mask);
    answer += (n - differentRow) * 2;
    return answer;
  }
};
// @lc code=end

