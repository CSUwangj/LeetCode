/*
 * @lc app=leetcode id=1569 lang=cpp
 *
 * [1569] Number of Ways to Reorder Array to Get Same BST
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int MOD = 1e9 + 7;
constexpr int qmul(int a, int b, int m) {
  int result = 0;
  while(b) {
    if(b & 1) {
      result += a;
      result %= m;
    }
    a += a;
    a %= m;
    b >>= 1;
  }
  return result;
}
constexpr int qpow(int b, int e, int m) {
  int result = 1;
  while(e) {
    if(e & 1) {
      result = qmul(result, b, m);
    }
    b = qmul(b, b, m);
    e >>= 1;
  }
  return result;
}
constexpr int inv(int a) {
  return qpow(a, MOD - 2, MOD);
}

constexpr int C(int m, int n) {
  int result = 1;
  for(int i = max(m, n - m) + 1; i <= n; ++i) {
    result = qmul(result, i, MOD);
  }
  for(int i = 1; i <= min(m, n - m); ++i) {
    result = qmul(result, inv(i), MOD);
  }
  return result;
}

class Solution {
  pair<int, int> children[1001];
  int nodes[1001];
  int len;
  void constructTree(vector<int> &nums) {
    len = nums.size();
    for(int i = 1; i <= len; ++i) {
      children[i] = {-1, -1};
      nodes[i] = 1;
    }
    construct(nums, 0, INT_MIN, INT_MAX);
  }
  void construct(vector<int> &nums, int index, int leftBound, int rightBound) {
    int root = nums[index];
    bool left = false;
    bool right = false;
    // cout << root << ' ' << leftBound << ' ' << rightBound << endl;
    for(int i = index + 1; i < nums.size() && !(left && right); i++) {
      if(!left && nums[i] < root && nums[i] > leftBound) {
        construct(nums, i, leftBound, min(rightBound, root));
        children[root].first = nums[i];
        nodes[root] += nodes[nums[i]];
        left = true;
      }
      if(!right && nums[i] > root && nums[i] < rightBound) {
        construct(nums, i, max(leftBound, root), rightBound);
        children[root].second = nums[i];
        nodes[root] += nodes[nums[i]];
        right = true;
      }
    }
  }
public:
  int numOfWays(vector<int>& nums) {
    constructTree(nums);
    // for(int i = 1; i <= len; ++i) {
    //   cout << i << ": " << children[i].first << " " << children[i].second << ' ' << nodes[i] << endl;
    // }
    queue<int> q;
    q.push(nums[0]);
    int answer = 1;
    while(q.size()) {
      int cur = q.front();
      q.pop();
      if(children[cur].first != -1) {
        q.push(children[cur].first);
        if(children[cur].second != -1) {
          answer = qmul(answer, C(nodes[children[cur].first], nodes[cur] - 1), MOD);
        }
      }
      if(children[cur].second != -1) {
        q.push(children[cur].second);
      }
    }
    return (answer + MOD - 1) % MOD;
  }
};

// Accepted
// 161/161 cases passed (396 ms)
// Your runtime beats 27.01 % of cpp submissions
// Your memory usage beats 97.41 % of cpp submissions (13.1 MB)
// @lc code=end

