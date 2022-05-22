/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct Time {
  long long total;
  double count;
  Time(): total(0), count(0) {}
};
class UndergroundSystem {
  unordered_map<string, unordered_map<string, Time>> time;
  unordered_map<int, int> checkInTime;
  unordered_map<int, string> checkInStation;
public:
  UndergroundSystem(){}

  void checkIn(int id, string stationName, int t) {
    checkInTime[id] = t;
    checkInStation[id] = stationName;
  }

  void checkOut(int id, string end, int t) {
    int interval = t - checkInTime[id];
    string start = checkInStation[id];
    time[start][end].total += interval;
    time[start][end].count += 1;
  }

  double getAverageTime(string start, string end) {
    return time[start][end].total / time[start][end].count;
  }
};

// Accepted
// 56/56 cases passed (157 ms)
// Your runtime beats 81.49 % of cpp submissions
// Your memory usage beats 75.4 % of cpp submissions (58.4 MB)
// @lc code=end

