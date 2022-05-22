/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
constexpr int MOD = 10007;
class MyHashSet {
  vector<int> container;
  inline int rev(int a) {
    return (a + 10006) * 3336 % MOD;
  }
  inline int nxt(int a) {
    return (a * 3 + 1) % MOD;
  }
public:
  MyHashSet(): container(MOD, -1) {}
  
  void add(int key) {
    int val = key;
    key %= MOD;
    while(container[key] != -1 && container[key] != val) {
      key = nxt(key);
    }
    container[key] = val;
  }
  
  void remove(int key) {
    int val = key;
    key %= MOD;
    while(container[key] != -1 && container[key] != val) {
      key = nxt(key);
    }
    if(container[key] == -1) return;
    int swapKey = key;
    int nextKey = nxt(swapKey);
    while(container[swapKey] != -1) {
      swapKey = nextKey;
      nextKey = nxt(swapKey);
    }
    container[key] = container[swapKey];
    container[swapKey] = -1;
  }
  
  bool contains(int key) {
    int val = key;
    key %= MOD;
    while(container[key] != -1 && container[key] != val) {
      key = nxt(key);
    }
    return container[key] == val;
  }
};

// Expected Wrong Answer
// Because swap can swap a value to it's front position which need to be calculated by rev
// @lc code=end

