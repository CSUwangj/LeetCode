/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
  void dfs(vector<vector<int>>& rooms, unordered_set<int> &opened, int cur) {
    opened.insert(cur);
    for(auto key : rooms[cur]) {
      if(!opened.count(key)) {
        dfs(rooms, opened, key);
      }
    }
  }
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    unordered_set<int> opened;
    dfs(rooms, opened, 0);
    return opened.size() == rooms.size();
  }
};

// Accepted
// 68/68 cases passed (19 ms)
// Your runtime beats 52.82 % of cpp submissions
// Your memory usage beats 20.02 % of cpp submissions (10.7 MB)
// @lc code=end

