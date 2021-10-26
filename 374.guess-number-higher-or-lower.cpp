/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
  int guessNumber(int n) {
    int begin = 1, end = n;
    while(begin < end) {
      int mid = begin + (end - begin) / 2;
      int res = guess(mid);
      if(res != 1) {
        end = mid;
      } else {
        begin = mid + 1;
      }
    }
    return begin;
  }
};

// Accepted
// 25/25 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 67.31 % of cpp submissions (5.9 MB)
// @lc code=end

