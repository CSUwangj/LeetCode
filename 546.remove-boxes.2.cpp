/*
 * @lc app=leetcode id=546 lang=cpp
 *
 * [546] Remove Boxes
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct Boxes {
  uint8_t color;
  uint8_t count;
};
const int N = 100;
uint16_t dp[N * N * N];
Boxes boxes[N];

class Solution {
  int n;
  uint16_t solve(uint8_t begin, uint8_t end, uint8_t cnt) {
    auto cache = dp + cnt * n * n + begin * n + end;
    if(*cache) return *cache;
    auto color = boxes[begin].color;
    if((end - begin) > 1 && boxes[end - 1].color == color) {
      cnt += boxes[end - 1].count;
      end -= 1;
    }
    cnt += boxes[begin].count;
    begin += 1;
    auto score = cnt * cnt;
    if(begin != end) {
      score += solve(begin, end, 0);
      for(auto mid = begin + 1; mid < end - 1; ++mid) {
        if(boxes[mid].color == color) {
          auto scoreRemove = solve(begin, mid, 0);
          auto scoreJoin = solve(mid, end, cnt);
          if(scoreRemove + scoreJoin > score) {
            score = scoreRemove + scoreJoin;
          }
        }
      }
    }
    // cout << int(begin) << ' ' << int(end) << ' ' << int(cnt) << ' ';
    // cout << score << endl;
    *cache = score;
    return score;
  }
public:
  int removeBoxes(vector<int>& boxesVec) {
    uint8_t pos = 0;
    uint8_t color = boxesVec.front();
    uint8_t count = 0;
    for(auto i : boxesVec) {
      if(i == color) {
        count += 1;
      } else {
        boxes[pos].count = count;
        boxes[pos].color = color;
        pos += 1;
        color = i;
        count = 1;
      }
    }
    boxes[pos].count = count;
    boxes[pos].color = color;
    n = pos + 1;
    if(n == 1) return boxes[0].count * boxes[0].count;
    memset(dp, 0, sizeof(uint16_t) * n * n * n);
    return solve(0, n, 0);
  }
};

// Accepted
// 62/62 cases passed (12 ms)
// Your runtime beats 96.3 % of cpp submissions
// Your memory usage beats 97.13 % of cpp submissions (9.7 MB)
// @lc code=end

