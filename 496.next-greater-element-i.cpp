/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        vector<int> monoStack;
        for(auto it = nums2.rbegin(); it != nums2.rend(); ++it) {
            while(monoStack.size() && monoStack.back() <= *it) monoStack.pop_back();
            nextGreater[*it] = monoStack.size() ? monoStack.back() : -1;
            monoStack.push_back(*it);
        }
        vector<int> answer(nums1.size());
        for(int i = 0; i < nums1.size(); ++i) {
            answer[i] = nextGreater[nums1[i]];
        }
        return answer;
    }
};
// @lc code=end

