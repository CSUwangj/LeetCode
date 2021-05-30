/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start
class Solution {
public:
  int lenLongestFibSubseq(vector<int>& arr) {
    unordered_map<int, unordered_map<int, int>> mp;
    unordered_set<int> has;
    int len = arr.size();
    int answer = 0;
    for(auto i : arr) has.insert(i);
    for(int i = 2; i < len; ++i) {
      for(int j = i - 1; j >= 0 && arr[j] * 2 > arr[i]; --j) {
        int gt = arr[i];
        int lt = arr[j];
        int diff = gt - lt;
        if(has.count(diff)) {
          mp[gt][lt] = mp[lt][diff] + 1;
          answer = max(mp[gt][lt], answer);
        }
      }
    }
    return answer ? answer + 2 : 0;
  }
};
// @lc code=end

