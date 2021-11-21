/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool has[128] = {false};
        int head = 0, tail = 0;
        int answer = 0;
        int len = s.length();
        while(head < len) {
            if(!has[s[head]]) {
                has[s[head]] = true;
                ++head;
                answer = max(head-tail, answer);
            } else {
                while(has[s[head]]) {
                    has[s[tail]] = false;
                    ++tail;
                }
            }
        }
        return answer;
    }
};

// Accepted
// 987/987 cases passed (4 ms)
// Your runtime beats 96.63 % of cpp submissions
// Your memory usage beats 89.6 % of cpp submissions (7 MB)
// @lc code=end

