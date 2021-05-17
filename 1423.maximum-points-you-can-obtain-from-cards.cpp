/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int len = cardPoints.size();
		vector<int> sum(len + 1);
		vector<int> rsum(len + 1);
		for(int i = 0; i < len; ++i) {
			sum[i + 1] = cardPoints[i] + sum[i];
			rsum[i + 1] = cardPoints[len - 1 - i] + rsum[i];
		}
		int answer = 0;
		for(int i = 0; i <=k; ++i) {
			answer = max(answer, sum[i] + rsum[k - i]);
		}
		return answer;
	}
};
// @lc code=end

