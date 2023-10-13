/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Arr {
  MountainArray &mountainArr;
  map<int, int> arr;
  public:
  Arr(MountainArray &m): mountainArr(m) {}

  int &operator[](int index) {
    if(arr.count(index)) return arr[index];
    arr[index] = mountainArr.get(index);
    return arr[index];
  }
};

class Solution {
public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    Arr a(mountainArr);
    int len = mountainArr.length();
    int low = 1;
    int high = len - 2;
    int peak;
    while(low <= high) {
      int mid = (low + high) / 2;
      if(a[mid] > a[mid - 1] && a[mid] > a[mid + 1]) {
        peak = mid;
        break;
      } else if(a[mid] > a[mid - 1]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    low = 0;
    high = peak;
    while(low < high) {
      int mid = (low + high) / 2;
      if(a[mid] < target) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    cout << low << ' ' << high << endl;
    if(a[low] == target) return low;
    low = peak;
    high = len - 1;
    while(low < high) {
      int mid = (low + high) / 2;
      if(a[mid] > target) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    if(a[low] == target) return low;
    return -1;
  }
};

// Accepted
// 79/79 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 14.97 % of cpp submissions (7.5 MB)
// @lc code=end

