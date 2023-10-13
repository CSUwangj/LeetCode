/*
 * @lc app=leetcode id=2542 lang=cpp
 *
 * [2542] Maximum Subsequence Score
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  using pi = pair<int, int>;
public:
  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pi> pairs;
    pairs.reserve(nums1.size());
    for(int i = 0; i < nums1.size(); ++i) {
      pairs.push_back({nums2[i], nums1[i]});
    }
    sort(pairs.begin(), pairs.end(), greater<pi>());
    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0;
    int count = 0;
    long long answer = 0;
    for(const auto &[factor, num] : pairs) {
      pq.push(num);
      count += 1;
      sum += num;
      if(count > k) {
        sum -= pq.top();
        pq.pop();
        count -= 1;
      }
      if(count == k) {
        answer = max(answer, sum * factor);
      }
    }
    return answer;
  }
};

// Accepted
// 28/28 cases passed (205 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 95.07 % of cpp submissions (87.2 MB)
// @lc code=end

