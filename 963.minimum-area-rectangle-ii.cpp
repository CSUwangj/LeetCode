/*
 * @lc app=leetcode id=963 lang=cpp
 *
 * [963] Minimum Area Rectangle II
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
	double minAreaFreeRect(vector<vector<int>>& points) {
		set<vector<int>>num;
		for(auto &s : points) {
      num.insert(s);
    }

		double answer = DBL_MAX;
    int len = points.size();
		for(int i = 0; i < len - 2; ++i){
			for(int j = i + 1; j < len - 1; ++j){
				for(int k = j + 1; k < len; ++k){
					double slop_y1 = points[j][1] - points[i][1];
					double slop_x1 = points[j][0] - points[i][0];
					double slop_y2 = points[k][1] - points[i][1];
					double slop_x2 = points[k][0] - points[i][0];
          // cout << slop_y1 << " " << slop_y2 << " " << slop_x1 << " " << slop_x2 << endl;
					if(slop_y1 * slop_y2 + slop_x1 * slop_x2 != 0) continue;

					int lasty = slop_y1 + points[k][1];
					int lastx = slop_x1 + points[k][0];
          // cout << lasty << " " << lastx << endl;

					if(num.count({lastx, lasty})){                        
						answer = min(answer, sqrt(slop_y1 * slop_y1 + slop_x1 * slop_x1) * sqrt(slop_y2 * slop_y2 + slop_x2 * slop_x2));
					}
				}
			}
		}

		return answer == DBL_MAX ? 0 : answer;
	}
};

// Accepted
// 109/109 cases passed (32 ms)
// Your runtime beats 89.34 % of cpp submissions
// Your memory usage beats 71.31 % of cpp submissions (9.8 MB)
// @lc code=end

