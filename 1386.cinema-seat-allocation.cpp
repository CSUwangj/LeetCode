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
const int MASK_MID   = 0B0001111000;
const int MASK_LEFT  = 0B0111100000;
const int MASK_RIGHT = 0B0000011110;
const int INIT_MASK  = 0B1111111111;
class Solution {
public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, int> mask;
    for(auto &seat : reservedSeats) {
      if(!mask.count(seat[0])) {
        mask[seat[0]] = INIT_MASK;
      }
      mask[seat[0]] ^= (1 << (seat[1] - 1));
    }
    int answer = (n - mask.size()) * 2;
    // cout << answer << endl;
    for(auto [_, m] : mask) {
      // cout << _ << ' ' << bitset<10>(m) << endl;
      if(((m & MASK_LEFT) == MASK_LEFT) || ((m & MASK_RIGHT) == MASK_RIGHT)) {
        answer += ((m & MASK_LEFT) == MASK_LEFT) + ((m & MASK_RIGHT) == MASK_RIGHT);
      } else {
        answer += ((m & MASK_MID) == MASK_MID);
      }
    }
    return answer;
  }
};
// @lc code=end

