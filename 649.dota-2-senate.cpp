/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start
class Solution {
public:
  string predictPartyVictory(string senate) {
    queue<bool> q;
    int leftR = 0;
    int leftD = 0;
    int banR = 0;
    int banD = 0;
    for(auto senate : senate) {
      q.push(senate == 'R');
      leftD += senate != 'R';
      leftR += senate == 'R';
    }

    while(leftD && leftR) {
      bool R = q.front();
      q.pop();
      if(R) {
        if(banR) {
          banR -= 1;
          leftR -= 1;
        } else {
          banD += 1;
          q.push(R);
        }
      } else {
        if(banD) {
          banD -= 1;
          leftD -= 1;
        } else {
          banR += 1;
          q.push(R);
        }
      }
    }

    return leftR ? "Radiant" : "Dire";
  }
};

// Accepted
// 82/82 cases passed (8 ms)
// Your runtime beats 72.14 % of cpp submissions
// Your memory usage beats 81.3 % of cpp submissions (7.1 MB)
// @lc code=end

