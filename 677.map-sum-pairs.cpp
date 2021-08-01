/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 */

// @lc code=start
struct Node {
  int sum = 0;
  Node *children[26] = {};
};
class MapSum {
  Node *root = nullptr;
  unordered_map<string, int> kv;
public:
  MapSum() {
    root = new Node();
  }
  
  void insert(string key, int val) {
    int diff = val;
    if(kv.count(key)) diff = val - kv[key];
    auto cur = root;
    for(auto c : key) {
      if(!(cur->children[c - 'a'])) cur->children[c - 'a'] = new Node();
      cur = cur->children[c - 'a'];
      cur->sum += diff;
    }
    kv[key] = val;
  }
  
  int sum(string prefix) {
    auto cur = root;
    for(auto c : prefix) {
      if(!(cur->children[c - 'a'])) return 0;
      cur = cur->children[c - 'a'];
    }
    return cur->sum;
  }
};

// Accepted
// 34/34 cases passed (4 ms)
// Your runtime beats 68.72 % of cpp submissions
// Your memory usage beats 60.16 % of cpp submissions (8.1 MB)
// @lc code=end

