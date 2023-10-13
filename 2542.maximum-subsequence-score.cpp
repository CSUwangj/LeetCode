/*
 * @lc app=leetcode id=2542 lang=cpp
 *
 * [2542] Maximum Subsequence Score
 */

// @lc code=start
class Solution {
public:
  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> indice(nums1.size());
    for(int i = 1; i < nums1.size(); ++i) {
      indice[i] = i;
    }
    sort(indice.begin(), indice.end(), [&](int a, int b) {
      return nums2[a] > nums2[b];
    });
    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0;
    int count = 0;
    long long answer = 0;
    for(auto i : indice) {
      pq.push(nums1[i]);
      count += 1;
      sum += nums1[i];
      if(count > k) {
        sum -= pq.top();
        pq.pop();
        count -= 1;
      }
      if(count == k) {
        answer = max(answer, sum * nums2[i]);
      }
    }
    return answer;
  }
};

// Accepted
// 28/28 cases passed (323 ms)
// Your runtime beats 32.51 % of cpp submissions
// Your memory usage beats 96.8 % of cpp submissions (85.8 MB)
// @lc code=end

