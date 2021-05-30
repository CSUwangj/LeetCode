/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
const int mask[] = {
  100000000,
  10000000,
  1000000,
  100000,
  10000,
  1000,
  100,
  10,
  1,
};
struct Node {
  Node* children[10] = {};
};
void insert(Node *root, int num) {
  auto cur = root;
  for(int i = 0; i < 9; ++i) {
    int digit = num / mask[i] % 10;
    if(!(cur->children[digit])) {
      cur->children[digit] = new Node();
    }
    cur = cur->children[digit];
  }
}

class Solution {
  int answer = INT_MIN;
  int prev = INT_MAX;
  void solve(Node *cur, int num, int rest) {
    if(!rest) {
      // cout << num << ' '<< prev << endl;
      answer = max(answer, num - prev);
      prev = num;
      return;
    }
    for(int i = 0; i < 10; ++i) {
      if(cur->children[i]) {
        solve(cur->children[i], num * 10 + i, rest - 1);
      }
    }
  }
public:
  int maximumGap(vector<int>& nums) {
    // cout << "$$$$$$$$$$$$"<<endl;
    if(nums.size() < 2) return 0;
    Node *root = new Node();
    bool has1e9 = false;
    for(auto i : nums) {
      prev = min(i, prev);
      if(i == 1000000000) {
        has1e9 = true;
        continue;
      }
      insert(root, i);
    }
    solve(root, 0, 9);
    if(has1e9) {
      answer = max(answer, 1000000000 - prev);
    }
    return answer;
  }
};
// @lc code=end

