/*
 * @lc app=leetcode id=1629 lang=cpp
 *
 * [1629] Slowest Key
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
  char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    int len = releaseTimes.size();
    int curTime = 0;
    char answer = ' ';
    int pressTime = 0;
    for(int i = 0; i < len; ++i) {
      if(releaseTimes[i] - curTime > pressTime || (releaseTimes[i] - curTime == pressTime && keysPressed[i] > answer)) {
        pressTime = releaseTimes[i] - curTime;
        answer = keysPressed[i];
      }
      curTime = releaseTimes[i];
    }
    return answer;
  }
};

// Accepted
// 105/105 cases passed (4 ms)
// Your runtime beats 97.21 % of cpp submissions
// Your memory usage beats 22.91 % of cpp submissions (10.8 MB)
// @lc code=end

