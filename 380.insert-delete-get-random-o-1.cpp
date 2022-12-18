/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class RandomizedSet {
  vector<int> container;
  map<int, int> index;
public:
  RandomizedSet() { }
  
  bool insert(int val) {
    if(index.count(val)) return false;
    index[val] = container.size();
    container.push_back(val);
    return true;
  }
  
  bool remove(int val) {
    if(!index.count(val)) return false;
    int i = index[val];
    int back = container.back();
    index[back] = i;
    container[i] = back;
    container.pop_back();
    index.erase(val);
    return true;
  }
  
  int getRandom() {
    return container[rand() % container.size()];
  }
};

// Accepted
// 19/19 cases passed (458 ms)
// Your runtime beats 64.02 % of cpp submissions
// Your memory usage beats 6.2 % of cpp submissions (97.9 MB)
// @lc code=end

