/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 */

// @lc code=start
class SnapshotArray {
  vector<map<int, int>> arr;
  int snapsCount = 0;
public:
  SnapshotArray(int length) {
    arr.resize(length);
  }
  
  void set(int index, int val) {
    arr[index][snapsCount] = val;
  }
  
  int snap() {
    snapsCount += 1;
    return snapsCount - 1;
  }
  
  int get(int index, int snap_id) {
    if(arr[index].empty()) return 0;
    auto it = arr[index].upper_bound(snap_id);
    if(it == arr[index].begin()) return 0;
    --it;
    return it->second;
  }
};

// Accepted
// 74/74 cases passed (409 ms)
// Your runtime beats 50.22 % of cpp submissions
// Your memory usage beats 40.09 % of cpp submissions (146.5 MB)
// @lc code=end

