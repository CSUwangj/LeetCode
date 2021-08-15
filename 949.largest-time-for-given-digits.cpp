/*
 * @lc app=leetcode id=949 lang=cpp
 *
 * [949] Largest Time for Given Digits
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
  string largestTimeFromDigits(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    string answer = ":::::";
    do {
      if(arr[0] > 2) break;
      if(arr[0] == 2 && arr[1] > 3) break;
      if(arr[2] > 5) continue;
      answer[0] = arr[0] + '0';
      answer[1] = arr[1] + '0';
      answer[3] = arr[2] + '0';
      answer[4] = arr[3] + '0';
    } while(next_permutation(arr.begin(), arr.end())); 
    return answer[0] != ':' ? answer : "";
  }
};

// Accepted
// 172/172 cases passed (4 ms)
// Your runtime beats 56.47 % of cpp submissions
// Your memory usage beats 17.45 % of cpp submissions (9.7 MB)
// @lc code=end

