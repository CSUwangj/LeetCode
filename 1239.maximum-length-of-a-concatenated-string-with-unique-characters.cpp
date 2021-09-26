/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class Solution {
  int answer = 0;
  int len;
  vector<int> masks;
  vector<int> lens;
  void init(vector<string>& arr) {
    len = arr.size();
    masks.resize(len);
    lens.resize(len);

    for(int i = 0; i < len; ++i) {
      lens[i] = arr[i].length();
      for(auto c : arr[i]) {
        int m = (1 << (c - 'a'));
        if(m & masks[i]) {
          masks[i] = 0;
          lens[i] = 0;
          break;
        }
        masks[i] |= m;
      }
    }
  }

  void solve(int index = 0, int mask = 0, int length = 0) {
    if(index == len) {
      if(length > answer) answer = length;
      return;
    }
    solve(index + 1, mask, length);
    if(lens[index] && (masks[index] & mask) == 0) {
      solve(index + 1, mask | masks[index], length + lens[index]);
    }
  }
public:
  int maxLength(vector<string>& arr) {
    init(arr);
    solve();
    return answer;
  }
};

// Accepted
// 85/85 cases passed (4 ms)
// Your runtime beats 95.24 % of cpp submissions
// Your memory usage beats 93.33 % of cpp submissions (8 MB)
// @lc code=end

