/*
 * @lc app=leetcode id=1603 lang=cpp
 *
 * [1603] Design Parking System
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class ParkingSystem {
  int parkingLot[4];
public:
  ParkingSystem(int big, int medium, int small) {
    parkingLot[1] = big;
    parkingLot[2] = medium;
    parkingLot[3] = small;
  }
  
  bool addCar(int carType) {
    if(!parkingLot[carType]) return false;
    parkingLot[carType] -= 1;
    return true;
  }
};

// Accepted
// 102/102 cases passed (46 ms)
// Your runtime beats 99.19 % of cpp submissions
// Your memory usage beats 99.71 % of cpp submissions (32.9 MB)
// @lc code=end

