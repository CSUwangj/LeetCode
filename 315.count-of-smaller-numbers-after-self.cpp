/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
#define lowbit(x) (x & (-x))

const int SZ = 20001;
const int OFFSET = 10001;
class Solution {
  int BITS[SZ + 1];

  void add(int x) {
    while(x <= SZ) {
      BITS[x] += 1;
      x += lowbit(x);
    }
  }

  int sum(int x) {
    int result = 0;
    while(x) {
      result += BITS[x];
      x -= lowbit(x);
    }
    return result;
  }
public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> answer;
    for(int i = nums.size() - 1; i >= 0; --i) {
      int n = nums[i] + OFFSET;
      answer.push_back(sum(n - 1));
      add(n);
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 65/65 cases passed (242 ms)
// Your runtime beats 91.76 % of cpp submissions
// Your memory usage beats 96.24 % of cpp submissions (73.4 MB)
// @lc code=end

